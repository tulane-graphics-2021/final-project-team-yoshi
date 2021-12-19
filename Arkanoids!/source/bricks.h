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
public:
    vec2 bricks_vert[8];
    vec3 bricks_color[8];
    struct {
        vec2 loc;
        vec3 color;
        bool brick_hit = {false};
        bool need_reset = {false};
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
    
    
    bricks(vec2 position, vec3 color);
    
    bool is_destroyed(){
        return state.brick_hit;
    }
    
    bool is_collision(vec2 point){
        
    }
    vec2 get_position(int index){
        return bricks_vert[index];
    }
    vec3 get_color(int index){
        return bricks_color[index];
    }
    
    void update_state();

    void gl_init();
    
    void draw(mat4 proj);
    bool Remove();
};


#endif /* bricks_h */
