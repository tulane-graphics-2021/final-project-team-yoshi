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
        float x_pos;
        bool launched = false;
        bool ball_on_bar;
        bool ball_on_brick;
		float x_i;
		float x_f;
		int tries = 0;
		int hits = 0;
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
    
    inline void launch(){
        state.launched = true;
    }

    inline void reflect(vec2 ob_1a,vec2 ob_1b, vec2 ob_1c, vec2 ob_2a){
        state.ball_on_bar = false;
        if((ob_2a.y <= -6.875) && (ob_2a.x > ob_1a.x) && (ob_2a.x < ob_1b.x)){
            state.ball_on_bar = true;
            float center_trans = -ob_1c.x;
            state.x_pos = ball_vert[0].x + center_trans;
        }
    }
        
    inline void shiftLeft() {
        for (int i = 0; i < 6; i++){
            ball_vert[i].x += -0.5;
        }
        
        // Create a vertex array object
        glBindVertexArray( GLvars.vao );
        
        //Generate buffer to hold our vertex data
        //Set GL state to use this buffer
        glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
        
        //Create GPU buffer to hold vertices and color
        glBufferData( GL_ARRAY_BUFFER, sizeof(ball_vert) + sizeof(ball_color), NULL, GL_STATIC_DRAW );
        //First part of array holds vertices
        glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ball_vert), ball_vert );
        //Second part of array hold colors (offset by sizeof(triangle))
        glBufferSubData( GL_ARRAY_BUFFER, sizeof(ball_vert), sizeof(ball_color), ball_color );
    }
    
    inline void shiftRight(){
        for (int i = 0; i < 6; i++){
            ball_vert[i].x += 0.5;
        }
        // Create a vertex array object
        glBindVertexArray( GLvars.vao );
        
        //Generate buffer to hold our vertex data
        //Set GL state to use this buffer
        glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
        
        //Create GPU buffer to hold vertices and color
        glBufferData( GL_ARRAY_BUFFER, sizeof(ball_vert) + sizeof(ball_color), NULL, GL_STATIC_DRAW );
        //First part of array holds vertices
        glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ball_vert), ball_vert );
        //Second part of array hold colors (offset by sizeof(triangle))
        glBufferSubData( GL_ARRAY_BUFFER, sizeof(ball_vert), sizeof(ball_color), ball_color );
    }
    
    vec2 get_ball_vert(int index){
        return ball_vert[index];
    }
    void update_state();
    
    void gl_init();
    
    void draw(mat4 proj);
    bool Remove();
};

#endif /* ball_h */
