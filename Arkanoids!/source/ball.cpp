//
//  ball.cpp
//  balls
//
//  Created by Sara Marie on 10/12/21.
//

#include "common.h"
//ball constructor
ball::ball(){
    state.velocity = vec2(0.18, 0.18);

};

//Called everytime an animation tick happens

void ball::update_state(){
    state.position = ball_vert[0];
    if (ball_vert[0].y < -7.55){            // if ball hits bottom
    
        ball_vert[0].x = 0;
        ball_vert[0].y = -6.75;
        
        ball_vert[1].x = -0.125;
        ball_vert[1].y = -0.125-6.72;
        
        ball_vert[2].x = 0.125;
        ball_vert[2].y = -0.125-6.72;
        
        ball_vert[3].x = 0.125;
        ball_vert[3].y = 0.125-6.72;
        
        ball_vert[4].x = -0.125;
        ball_vert[4].y = 0.125-6.72;
        
        ball_vert[5].x = -0.125;
        ball_vert[5].y = -0.125-6.72;
        state.launched=false;
		state.tries += 1;
    }
	
	
    if(state.launched){
        state.position = ball_vert[0];

        if(ball_vert[0].y > 7.55){                 // if ball hits top
            state.velocity.y = -state.velocity.y;
        }

        
        if((ball_vert[0].x > 7.55) || (ball_vert[0].x < -7.55)){ // if ball hits side
            state.velocity.x = -state.velocity.x;
        }
        if(state.ball_on_bar){ // if ball hits paddle/bar
            if(state.x_pos > 0 ){ // if ball hits left side of bar, bounces left
                state.velocity.x = 0.18;
            }
            if(state.x_pos < 0){ // if ball hits right side of bar, bounces right
                state.velocity.x =  -0.18;
            }
            state.velocity.y = -state.velocity.y;
        }
        if(state.ball_on_brick){
			if(state.position.x > state.x_i + 0.5){
				state.velocity.x = 0.18;
			}
			if(state.position.x < state.x_f - 0.5){
				state.velocity.x = -0.18;
			}
            state.velocity.y = -state.velocity.y;
        }
        for(int i = 0; i < 6; i++){
            ball_vert[i] += state.velocity;
        }
        
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

//Initialize the gl state and variables
void ball::gl_init(){
    
    ball_vert[0] = vec2(0,-6.75); //center
    ball_vert[1] = vec2(-0.125,-0.125-6.72);
    ball_vert[2] = vec2(0.125,-0.125-6.72);
    ball_vert[3] = vec2(0.125,0.125-6.72);
    ball_vert[4] = vec2(-0.125,0.125-6.72);
    ball_vert[5] = vec2(-0.125,-0.125-6.72);
    
    for(int i = 0; i < 6; i++){
        ball_color[i] = vec3(1,1,1);
    }
    
    std::string vshader = shader_path + "vshader_ball.glsl";
    std::string fshader = shader_path + "fshader_ball.glsl";
    
    GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
    GLchar* fragment_shader_source = readShaderSource(fshader.c_str());
    
    GLvars.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(GLvars.vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
    glCompileShader(GLvars.vertex_shader);
    check_shader_compilation(vshader, GLvars.vertex_shader);
    
    GLvars.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(GLvars.fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
    glCompileShader(GLvars.fragment_shader);
    check_shader_compilation(fshader, GLvars.fragment_shader);
    
    GLvars.program = glCreateProgram();
    glAttachShader(GLvars.program, GLvars.vertex_shader);
    glAttachShader(GLvars.program, GLvars.fragment_shader);
    
    glLinkProgram(GLvars.program);
    check_program_link(GLvars.program);
    
    glBindFragDataLocation(GLvars.program, 0, "fragColor");
    
    GLvars.vpos_location  = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vcolor_location = glGetAttribLocation(GLvars.program, "vColor" );
    GLvars.M_location = glGetUniformLocation(GLvars.program, "M" );
    
    // Create a vertex array object
    glGenVertexArrays( 1, &GLvars.vao );
    //Set GL state to use vertex array object
    glBindVertexArray( GLvars.vao );
    
    //Generate buffer to hold our vertex data
    glGenBuffers( 1, &GLvars.buffer );
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );
    
    //Create GPU buffer to hold vertices and color
    glBufferData( GL_ARRAY_BUFFER, sizeof(ball_vert) + sizeof(ball_color), NULL, GL_STATIC_DRAW );
    //First part of array holds vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(ball_vert), ball_vert );
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(ball_vert), sizeof(ball_color), ball_color );
    
    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vcolor_location );
    
    glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( GLvars.vcolor_location, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(ball_vert)) );
    
    glBindVertexArray(0);
    
}
//Draw a ball
void ball::draw(mat4 proj){
    proj = Scale(0.125, 0.125, 0.125);
    glUseProgram( GLvars.program );
    glBindVertexArray( GLvars.vao );
    
    //If you have a modelview matrix, pass it with proj
    glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, proj );
    //Draw something
    glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
    
    
    
    glBindVertexArray(0);
    glUseProgram(0);
    
}
