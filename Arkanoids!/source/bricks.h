//
//  bricks.h
//  bricksS
//
//  Created by Sara Marie on 10/12/21.
//

#ifndef bricks_h
#define bricks_h
#include "common.h"
class bricks{
	
	vec2 bricks_vert[4];
	vec3 bricks_color[4];
	struct {
		vec2 loc;
		vec3 color;
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
	
	std::vector < bricks > bricks_obj;
public:
	
	
	bricks(vec2 position);
	
	bool is_collision(vec2 point){
		
	}
	
	
	
	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	bool Remove();
};


#endif /* bricks_h */
