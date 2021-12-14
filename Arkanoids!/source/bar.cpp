//
// bar.cpp
//
// bar.cpp
// Asteroids
//
// Created by Brian Summa on 6/5/15.
//
//
#include "common.h"
//bar constructor
bar::bar(){
	
};
//Called everytime an animation tick happens
void bar::update_state(){
	
	if(bar_vert[1].x < - 7.5){
		stop_Left();
	}
	if(bar_vert[2].x > 7.5){
		stop_Right();
	}
	if (bar_vert[1].x > -7.5 && bar_vert[2].x < 7.5){
		move_Both();
	}
	state.cur_location = bar_vert[0];
	// Create a vertex array object
		glBindVertexArray( GLvars.vao );
		glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
		glBufferData( GL_ARRAY_BUFFER, sizeof(bar_vert) + sizeof(bar_color), NULL, GL_STATIC_DRAW );
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bar_vert), bar_vert);
		glBufferSubData( GL_ARRAY_BUFFER, sizeof(bar_vert), sizeof(bar_color), bar_color);
}

//Initialize the gl state and variables
void bar::gl_init(){
	//bar
	//!!!!!!!!Populate bar_vert and bar_color
	
	bar_vert[0] = vec2(0,-7);
	bar_vert[1] = vec2(-1,-6.875);
	bar_vert[2] = vec2(1,-6.875);
	bar_vert[3] = vec2(-1,-7.125);
	bar_vert[4] = vec2(1,-7.125);
	
	for(int i = 0; i < 5; i++){
		bar_color[i] = vec3(0.5, 0.5, 0.5);
	}
	std::string vshader = shader_path + "vshader_bar.glsl";
	std::string fshader = shader_path + "fshader_bar.glsl";
	
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
	glBufferData( GL_ARRAY_BUFFER, sizeof(bar_vert) + sizeof(bar_color), NULL, GL_STATIC_DRAW );
	//First part of array holds vertices
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bar_vert), bar_vert );
	//Second part of array hold colors (offset by sizeof(triangle))
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(bar_vert), sizeof(bar_color), bar_color );
	
	glEnableVertexAttribArray(GLvars.vpos_location);
	glEnableVertexAttribArray(GLvars.vcolor_location );
	
	glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
	glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(bar_vert)) );
	
	glBindVertexArray(0);
	
}
//Draw a bar
void bar::draw(mat4 proj){
	proj = Scale(0.125, 0.125, 0);
	glUseProgram( GLvars.program );
	glBindVertexArray( GLvars.vao );
	
	//If you have a modelview matrix, pass it with proj
	glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj );
	//Draw something
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);
	
	
	
	glBindVertexArray(0);
	glUseProgram(0);
	
}
