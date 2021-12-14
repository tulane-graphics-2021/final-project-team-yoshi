//
//  bricks.cpp
//  bricks
//
//  Created by Sara Marie on 10/17/21.
//

#include "common.h"
//bricks constructor
bricks::bricks(vec2 position){
	bricks_vert[0] = vec2(-0.5, -0.5);
	bricks_vert[1] = vec2(-0.5,  1);
	bricks_vert[2] = vec2( 3.0, -0.5);
	bricks_vert[3] = vec2( 3.0,  1);
	for (int i = 0; i < 4; i ++){
		bricks_vert[i] += position;
	}
	
	
	for(int i = 0; i < 4; i++){
		bricks_color[i] = vec3(0, 1, 0);
	}
};

//Called everytime an animation tick happens
void bricks::update_state(){
	
	// Create a vertex array object
	glBindVertexArray( GLvars.vao );
	
	//Generate buffer to hold our vertex data
	//Set GL state to use this buffer
	glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
	
	//Create GPU buffer to hold vertices and color
	glBufferData( GL_ARRAY_BUFFER, sizeof(bricks_vert) + sizeof(bricks_color), NULL, GL_STATIC_DRAW );
	//First part of array holds vertices
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bricks_vert), bricks_vert );
	//Second part of array hold colors (offset by sizeof(triangle))
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(bricks_vert), sizeof(bricks_color), bricks_color );
	
}

//Initialize the gl state and variables
void bricks::gl_init(){
	
//	bricks_vert[0] = vec2(0-6,-7+15);
//	bricks_vert[1] = vec2(-1-6,-6.875+15);
//	bricks_vert[2] = vec2(1-6,-6.875+15);
//	bricks_vert[3] = vec2(-1-6,-7.125+15);
//	bricks_vert[4] = vec2(1-6,-7.125+15);
	
	
	
	std::string vshader = shader_path + "vshader_bricks.glsl";
	std::string fshader = shader_path + "fshader_bricks.glsl";
	
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
	glBufferData( GL_ARRAY_BUFFER, sizeof(bricks_vert) + sizeof(bricks_color), NULL, GL_STATIC_DRAW );
	//First part of array holds vertices
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bricks_vert), bricks_vert );
	//Second part of array hold colors (offset by sizeof(triangle))
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(bricks_vert), sizeof(bricks_color), bricks_color );
	
	glEnableVertexAttribArray(GLvars.vpos_location);
	glEnableVertexAttribArray(GLvars.vcolor_location );
	
	glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
	glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(bricks_vert)) );
	
	glBindVertexArray(0);
	
}
//Draw a bricks
void bricks::draw(mat4 proj){
	proj = Scale(0.025, 0.025, 0.025);
	glUseProgram( GLvars.program );
	glBindVertexArray( GLvars.vao );
	
	//If you have a modelview matrix, pass it with proj
	glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj );
	//Draw something
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glBindVertexArray(0);
	glUseProgram(0);
	
}
