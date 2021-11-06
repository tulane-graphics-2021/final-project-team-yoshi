//
//  Bullet.h
//  ASTEROIDS
//
//  Created by Sara Marie on 10/17/21.
//

#ifndef Bullet_h
#define Bullet_h
#include "common.h"
class bullet{
	public:
	vec2 bullet_vert[5];
	vec3 bullet_color[5];
	
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
	
	
	bullet(/*vec2 position, vec2 velocity*/);
	inline void pew_pew(vec2 position, vec2 velocity){
		state.position = position;
		state.velocity = velocity;
	}
	inline void start_thruster(){ state.follow= true;}
	inline void stop_thruster() { state.follow= false;}
	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	bool Remove();
};

#endif /* Bullet_h */
