//
// Ship.cpp
//
// Ship.cpp
// Asteroids
//
// Created by Brian Summa on 6/5/15.
//
//
#include "common.h"
//Ship constructor
Ship::Ship(){
	
};
//Called everytime an animation tick happens
void Ship::update_state(){
	state.cur_location = ship_vert[0]; //center
	state.pointing = ship_vert[3] - state.cur_location;
	vec2 a = state.pointing * 3;
	state.velocity = a * 0.5 * 0.98;
	if(state.thruster_on) {
		state.cur_location = ship_vert[0]; //center
		state.pointing = ship_vert[3] - state.cur_location;
		vec2 a = state.pointing * 3;
		
		if (a.x >= 3 || a.x <= -3){
			if (a.x >= 3){
				a.x = 3;
			}
			if (a.x <= -3){
				a.x = -3;
			}
		}
		if(a.y >= 3 || a.y <= -3){
			if (a.y >= 3){
				a.y = 3;
			}
			if (a.y <= -3){
				a.y = -3;
			}
		}
		
		state.velocity = a * 0.5 * 0.98;
		if(state.velocity.x >= 10 || state.velocity.x <= -10){
			if (state.velocity.x >= 10){
				state.velocity.x = 10;
			}
			if (state.velocity.x <= -10){
				state.velocity.x = -10;
			}
		}
		if(state.velocity.y >= 10 || state.velocity.y <= -10){
			if (state.velocity.y >= 10){
				state.velocity.y = 10;
			}
			if (state.velocity.y <= -10){
				state.velocity.y = -10;
			}
		}
		
		state.cur_location = state.velocity * 0.5 * 0.98;
		if (ship_vert[3].x >= 8){
			for(int i = 0; i < 10; i ++){
				ship_vert[i].x  -= 15;
			}
		}
		if (ship_vert[3].x <= -8){
			for(int i = 0; i < 10; i ++){
				ship_vert[i].x  += 15;
			}
		}
		if (ship_vert[3].y >= 8){
			for(int i = 0; i < 10; i ++){
				ship_vert[i].y  -= 15;
			}
		}
		if (ship_vert[3].y <= -8){
			for(int i = 0; i < 10; i ++){
				ship_vert[i].y  += 15;
			}
		}
		for (int i = 0; i < 10; i++) {
			ship_vert[i] += state.cur_location;
		}
		
		// Create a vertex array object
		glBindVertexArray( GLvars.vao );
		glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
		glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ship_vert), ship_vert );
		glBufferSubData( GL_ARRAY_BUFFER, sizeof(ship_vert), sizeof(ship_color), ship_color );
		
	}
}
//Initialize the gl state and variables
void Ship::gl_init(){
	//Ship
	//!!!!!!!!Populate ship_vert and ship_color
	
	ship_vert[6] = vec2(-0.25, -0.375);
	ship_vert[7] = vec2(0.0, -1.0);
	ship_vert[8] = vec2(0.25, -0.375);
	ship_vert[9] = vec2(0, -0.25);
	
	ship_vert[0] = vec2(0,0);
	ship_vert[1] = vec2(0, -0.25);
	ship_vert[2] = vec2(-0.5, -0.5);
	ship_vert[3] = vec2(0, 0.5);
	ship_vert[4] = vec2(0.5, -0.5);
	ship_vert[5] = vec2(0, -0.25);
	
	ship_color[0] = vec3( 1.0, 1.0, 1.0);
	ship_color[1] = vec3( 1.0, 1.0, 1.0);
	ship_color[2] = vec3( 1.0, 1.0, 1.0);
	ship_color[3] = vec3( 1.0, 1.0, 1.0);
	ship_color[4] = vec3( 1.0, 1.0, 1.0);
	ship_color[5] = vec3( 1.0, 1.0, 1.0);
	
	ship_color[6] = vec3( 1.0, 0.0, 0.0);
	ship_color[7] = vec3( 1.0, 1.0, 0.0);
	ship_color[8] = vec3( 1.0, 0.0, 0.0);
	ship_color[9] = vec3(1.0, 0.0, 0.0);
	
	
	std::string vshader = shader_path + "vshader_Ship.glsl";
	std::string fshader = shader_path + "fshader_Ship.glsl";
	
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
	glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
	//First part of array holds vertices
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ship_vert), ship_vert );
	//Second part of array hold colors (offset by sizeof(triangle))
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(ship_vert), sizeof(ship_color), ship_color );
	
	glEnableVertexAttribArray(GLvars.vpos_location);
	glEnableVertexAttribArray(GLvars.vcolor_location );
	
	glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
	glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(ship_vert)) );
	
	glBindVertexArray(0);
	
}
//Draw a ship
void Ship::draw(mat4 proj){
	proj = Scale(0.125, 0.125, 0);
	glUseProgram( GLvars.program );
	glBindVertexArray( GLvars.vao );
	
	//If you have a modelview matrix, pass it with proj
	glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj );
	//Draw something
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
	
	if(state.thruster_on){
		//Maybe draw something different if the thruster is on
		glDrawArrays(GL_TRIANGLE_FAN,5,10);
		glDrawArrays(GL_TRIANGLE_FAN, 5, 10);
	}
	
	glBindVertexArray(0);
	glUseProgram(0);
	
}
