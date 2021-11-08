//
//  bricks.h
//  ASTEROIDS
//
//  Created by Sara Marie on 10/17/21.
//

#ifndef bricks_h
#define bricks_h
#include "common.h"
class bricks{
	public:
	vec2 bricks_vert[5];
	vec3 bricks_color[5];
	
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
	
	
	bricks();
	inline void pew_pew(vec2 position, vec2 velocity){
		
	}

	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	bool Remove();
};

#endif /* bricks_h */
