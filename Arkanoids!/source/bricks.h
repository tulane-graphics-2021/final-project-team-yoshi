//
//  ball.h
//  ballS
//
//  Created by Sara Marie on 10/12/21.
//

#ifndef ball_h
#define ball_h
#include "common.h"
class ball{
	
	vec2 ball_vert[20];
	vec3 ball_color[20];
	struct {
		vec2 cur_location;   //Current position of the center
		float angle;//Rotation angle
		vec2 pointing;//This function will be helpful to keep track of the direction the ship
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
	
	
	ball();
	
	bool is_collision(vec2 point){
		
	}
	
	inline void rotate() {
		
	}
	
	
	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	bool Remove();
};


#endif /* ball_h */
