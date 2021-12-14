//
//  bar.h
//  Asteroids
//
//  Created by Brian Summa on 6/5/15.
//
//

#ifndef __Asteroids__bar__
#define __Asteroids__bar__

#include "common.h"

#define _MAX_SPEED 10
#define _DAMPING 0.98
#define _ACC 3
#define _ROT 15

class bar{
public: 
	//Placeholders so everything compiles.  Customize for your bar
	vec2 bar_vert[5];
	vec3 bar_color[5];
	//Record of the bar's state
	struct {
		vec2 cur_location;   //Current position of the center
		float angle;         //Rotation angle
		vec2 pointing;       //Vector pointing to the front of the bar
		//This function will be helpful to keep track of the direction the bar
		//is pointing
		mat2 RotateZ2D( const GLfloat theta ){
			GLfloat angle = DegreesToRadians * theta;
			mat2 c;
			c[0][0] = c[1][1] = cos(angle);
			c[1][0] = sin(angle);
			c[0][1] = -c[1][0];
			return c;
		}
		vec2 velocity;       //Velocity
		bool move_left = true;
		bool move_right = true;
	} state;
	
	//OpenGL variables for a bar
	struct {
		GLuint vao;           //Vertex array object
		GLuint program;       //shader program
		GLuint buffer;        //Vertex buffer objects
		GLuint vertex_shader, fragment_shader;  //Shaders
		GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
		GLint M_location;     //Reference to matrix in shader
	} GLvars;
	
	
public:
	
	
	bar();
	inline void stop_Left(){
		state.move_left= false;
		state.move_right = true;
	}
	inline void stop_Right(){
		state.move_left = true;
		state.move_right = false;
	}
	inline void move_Both(){
		state.move_left = true;
		state.move_right = true;
	}
	inline void shiftLeft() {
		for (int i = 0; i < 5; i++){
			bar_vert[i].x += -0.5;
		}
		
		// Create a vertex array object
		glBindVertexArray( GLvars.vao );
		
		//Generate buffer to hold our vertex data
		//Set GL state to use this buffer
		glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
		
		//Create GPU buffer to hold vertices and color
		glBufferData( GL_ARRAY_BUFFER, sizeof(bar_vert) + sizeof(bar_color), NULL, GL_STATIC_DRAW );
		//First part of array holds vertices
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bar_vert), bar_vert );
		//Second part of array hold colors (offset by sizeof(triangle))
		glBufferSubData( GL_ARRAY_BUFFER, sizeof(bar_vert), sizeof(bar_color), bar_color );
	}
	
	inline void shiftRight(){
		for (int i = 0; i < 5; i++){
			bar_vert[i].x += 0.5;
		}
		// Create a vertex array object
		glBindVertexArray( GLvars.vao );
		
		//Generate buffer to hold our vertex data
		//Set GL state to use this buffer
		glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
		
		//Create GPU buffer to hold vertices and color
		glBufferData( GL_ARRAY_BUFFER, sizeof(bar_vert) + sizeof(bar_color), NULL, GL_STATIC_DRAW );
		//First part of array holds vertices
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(bar_vert), bar_vert );
		//Second part of array hold colors (offset by sizeof(triangle))
		glBufferSubData( GL_ARRAY_BUFFER, sizeof(bar_vert), sizeof(bar_color), bar_color );
	}
	
	void update_state();
	vec2 get_bar_vert(int index){
		return bar_vert[index];
	}
	void gl_init();
	
	void draw(mat4 proj);
	
};


#endif /* defined(__Asteroids__bar__) */
