//
//  asteroid.h
//  ASTEROIDS
//
//  Created by Sara Marie on 10/12/21.
//

#ifndef asteroid_h
#define asteroid_h
#include "common.h"
class asteroid{
	//vec2 asteroid_vert[20];
	//vec3 asteroid_color[20];
	vec2 asteroid_vert[20];
	vec3 asteroid_color[20];
	//Record of the ship's state
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
	
	
	asteroid();
	vec2 getAsteroid(int index){
		return asteroid_vert[index];
	}
	bool is_collision(vec2 point){
		bool collision = false;
		int j = 0;
		for(int i = 0; i < 20; j = i++){
			vec2 obj_pt_i = asteroid_vert[i];
			vec2 obj_pt_j = asteroid_vert[j];
			if(((obj_pt_i.y > point.y) != (obj_pt_j.y > point.y)) && (point.x < (obj_pt_j.x - obj_pt_i.x) * (point.y - obj_pt_i.y) / (obj_pt_j.y - obj_pt_i.y) + obj_pt_i.x)){
				collision = true;
				return collision;
			}
			else{
				collision = false;
				return collision;
			}
		}
	}
	
	inline void rotate() {
		for(int i = 0; i <20; i ++){
			state.cur_location = asteroid_vert[0];
			vec2 temp = state.cur_location + (state.RotateZ2D(state.angle) * (asteroid_vert[i] - state.cur_location));
			asteroid_vert[i] = temp;
		}
	}
	
	
	void update_state();
	
	void gl_init();
	
	void draw(mat4 proj);
	bool Remove();
};


#endif /* asteroid_h */
