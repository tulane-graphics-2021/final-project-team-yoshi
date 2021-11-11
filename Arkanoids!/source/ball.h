//
//  ball.h
//  ASTEROIDS
//
//  Created by Sara Marie on 10/17/21.
//

#ifndef ball_h
#define ball_h
#include "common.h"
class ball{
	public:
	vec2 ball_vert[6];
	vec3 ball_color[6];
	
	struct {
		vec2 velocity;       //Velocity
		vec2 position;
		bool follow;
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
	inline void bounce(/*vec2 position, vec2 velocity */){
		
	}

	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	bool Remove();
};

#endif /* ball_h */
