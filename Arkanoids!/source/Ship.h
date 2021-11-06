//
//  Ship.h
//  Asteroids
//
//  Created by Brian Summa on 6/5/15.
//
//

#ifndef __Asteroids__Ship__
#define __Asteroids__Ship__

#include "common.h"

#define _MAX_SPEED 10
#define _DAMPING 0.98
#define _ACC 3
#define _ROT 15
class Bullet{
	vec2 bull_vel[1];
};
class Ship{
public: 
	//Placeholders so everything compiles.  Customize for your ship
	vec2 ship_vert[10];
	vec3 ship_color[10];
	//Record of the ship's state
	struct {
		vec2 cur_location;   //Current position of the center
		float angle;         //Rotation angle
		vec2 pointing;       //Vector pointing to the front of the ship
		//This function will be helpful to keep track of the direction the ship
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
		bool thruster_on;    //Boolean if a thruster is on
	} state;
	
	//OpenGL variables for a ship
	struct {
		GLuint vao;           //Vertex array object
		GLuint program;       //shader program
		GLuint buffer;        //Vertex buffer objects
		GLuint vertex_shader, fragment_shader;  //Shaders
		GLint vpos_location, vcolor_location;   //reference to pos and color in shaders
		GLint M_location;     //Reference to matrix in shader
	} GLvars;
	
	
public:
	
	
	Ship();
	inline void start_thruster(){ state.thruster_on= true;}
	inline void stop_thruster() { state.thruster_on= false;}
	
	vec2 getShip(int index){
		return ship_vert[index];
	}
	vec2 getVelocity(){
		return state.velocity;
	}
	inline void rotateLeft() {
		//Do something
		for(int i = 0; i <10; i ++){
			state.cur_location = ship_vert[0];
			vec2 temp = state.cur_location + (state.RotateZ2D(20.0) * (ship_vert[i] - state.cur_location));
			ship_vert[i] = temp;
		}
		
		// Create a vertex array object
		glBindVertexArray( GLvars.vao );
		
		//Generate buffer to hold our vertex data
		//Set GL state to use this buffer
		glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
		
		//Create GPU buffer to hold vertices and color
		glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
		//First part of array holds vertices
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ship_vert), ship_vert );
		//Second part of array hold colors (offset by sizeof(triangle))
		glBufferSubData( GL_ARRAY_BUFFER, sizeof(ship_vert), sizeof(ship_color), ship_color );
	}
	
	inline void rotateRight(){
		//Do something
		for(int i = 0; i <10; i ++){
			state.cur_location = ship_vert[0];
			vec2 temp = state.cur_location + (state.RotateZ2D(-20.0) * (ship_vert[i] - state.cur_location));
			ship_vert[i] = temp;
		}
		
		// Create a vertex array object
		glBindVertexArray( GLvars.vao );
		
		//Generate buffer to hold our vertex data
		//Set GL state to use this buffer
		glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
		
		//Create GPU buffer to hold vertices and color
		glBufferData( GL_ARRAY_BUFFER, sizeof(ship_vert) + sizeof(ship_color), NULL, GL_STATIC_DRAW );
		//First part of array holds vertices
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ship_vert), ship_vert );
		//Second part of array hold colors (offset by sizeof(triangle))
		glBufferSubData( GL_ARRAY_BUFFER, sizeof(ship_vert), sizeof(ship_color), ship_color );
	}
	
	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	
};


#endif /* defined(__Asteroids__Ship__) */
