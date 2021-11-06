//
//  asteroid.cpp
//  asteroids
//
//  Created by Sara Marie on 10/12/21.
//

#include "common.h"
//asteroid constructor
asteroid::asteroid(){
};

//Called everytime an animation tick happens
void asteroid::update_state(){
	state.angle = 2.0;
	state.velocity = 3*(vec2(0.05, -0.01));
	
	if(asteroid_vert[0].y == 0){
		for(int i = 0; i < 20; i++){
			asteroid_vert[i].y  += 3;
		}
	}
	if (asteroid_vert[1].x >= 8){
		for(int i = 0; i < 20; i ++){
			asteroid_vert[i].x  -= 12;
		}
	}
	if (asteroid_vert[1].x <= -8){
		for(int i = 0; i < 20; i ++){
			asteroid_vert[i].x  += 12;
		}
	}
	if (asteroid_vert[1].y >= 8){
		for(int i = 0; i < 20; i ++){
			asteroid_vert[i].y  -= 12;
		}
	}
	if (asteroid_vert[1].y <= -8){
		for(int i = 0; i < 20; i ++){
			asteroid_vert[i].y  += 12;
		}
	}
	else{
		for (int i = 0; i < 20; i++) {
			asteroid_vert[i] += state.velocity;
		}
	}
	
	// Create a vertex array object
	glBindVertexArray( GLvars.vao );
	
	//Generate buffer to hold our vertex data
	//Set GL state to use this buffer
	glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
	
	//Create GPU buffer to hold vertices and color
	glBufferData( GL_ARRAY_BUFFER, sizeof(asteroid_vert) + sizeof(asteroid_color), NULL, GL_STATIC_DRAW );
	//First part of array holds vertices
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(asteroid_vert), asteroid_vert );
	//Second part of array hold colors (offset by sizeof(triangle))
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(asteroid_vert), sizeof(asteroid_color), asteroid_color );
	
}

//Initialize the gl state and variables
void asteroid::gl_init(){
	
	//Setting Asteroid Center to (0,0):
	asteroid_vert[0] = vec2(0,0);
	
	//Generate Random Angles for Asteroid Vertices:
	float pie = M_PI;
	float angle[20];
	for(int c = 0; c < 20; c++){
		angle[c] = (rand()) / (static_cast <float> (RAND_MAX/7));
	}
	//Put random angles in order:
	for(int i=0;i<20;i++){
		for(int j=i+1;j<20;j++){
			if(angle[i]>angle[j]){
				float temp  =angle[i];
				angle[i]=angle[j];
				angle[j]= temp;
			}
		}
	}
	
	//Asteroid Vertices:
	for(int i = 1; i <= 20; i++){
		if(i == 19){
			asteroid_vert[i] = asteroid_vert[1];
		}
		else{
			float r = 0.5;
			float x =  r*cos(angle[i]);
			float y =  r*sin(angle[i]);
			asteroid_vert[i] = vec2(x,y);}
	}
	//Asteroid Color:
	vec3 color = vec3(rand()/(float)RAND_MAX,rand()/(float)RAND_MAX,rand()/(float)RAND_MAX);
	for(int i =0; i < 20; i ++){
		asteroid_color[i] = color;
	}
	
	
	
	std::string vshader = shader_path + "vshader_asteroid.glsl";
	std::string fshader = shader_path + "fshader_asteroid.glsl";
	
	GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
	GLchar* fragment_shader_source = readShaderSource(fshader.c_str());
	
	GLvars.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(GLvars.vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
	glCompileShader(GLvars.vertex_shader);
	check_shader_compilation(vshader, GLvars.vertex_shader);
	
	GLvars.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(GLvars.fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
	glCompileShader(GLvars.fragment_shader);
	check_shader_compilation(fshader, GLvars.fragment_shader);
	
	GLvars.program = glCreateProgram();
	glAttachShader(GLvars.program, GLvars.vertex_shader);
	glAttachShader(GLvars.program, GLvars.fragment_shader);
	
	glLinkProgram(GLvars.program);
	check_program_link(GLvars.program);
	
	glBindFragDataLocation(GLvars.program, 0, "fragColor");
	
	GLvars.vpos_location  = glGetAttribLocation(GLvars.program, "vPos");
	GLvars.vcolor_location = glGetAttribLocation(GLvars.program, "vColor" );
	GLvars.M_location = glGetUniformLocation(GLvars.program, "M" );
	
	// Create a vertex array object
	glGenVertexArrays( 1, &GLvars.vao );
	//Set GL state to use vertex array object
	glBindVertexArray( GLvars.vao );
	
	//Generate buffer to hold our vertex data
	glGenBuffers( 1, &GLvars.buffer );
	//Set GL state to use this buffer
	glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
	
	//Create GPU buffer to hold vertices and color
	glBufferData( GL_ARRAY_BUFFER, sizeof(asteroid_vert) + sizeof(asteroid_color), NULL, GL_STATIC_DRAW );
	//First part of array holds vertices
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(asteroid_vert), asteroid_vert );
	//Second part of array hold colors (offset by sizeof(triangle))
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(asteroid_vert), sizeof(asteroid_color), asteroid_color );
	
	glEnableVertexAttribArray(GLvars.vpos_location);
	glEnableVertexAttribArray(GLvars.vcolor_location );
	
	glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
	glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(asteroid_vert)) );
	
	glBindVertexArray(0);
	
}
//Draw a asteroid
void asteroid::draw(mat4 proj){
	proj = Scale(0.25, 0.25, 0.25);
	glUseProgram( GLvars.program );
	glBindVertexArray( GLvars.vao );
	
	//If you have a modelview matrix, pass it with proj
	glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj );
	//Draw something
	glDrawArrays(GL_TRIANGLE_FAN, 0, 20);
	
	
	
	glBindVertexArray(0);
	glUseProgram(0);
	
}
