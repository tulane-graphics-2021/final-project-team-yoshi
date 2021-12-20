#include "common.h"

using namespace Angel;

bar bar;
ball ball;
std::vector<bricks> all_bricks;

int counter = 0;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
        if(bar.state.move_left){
            bar.shiftLeft();
            if(ball.state.launched == false){
                ball.shiftLeft();
            }
        }
    
    if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
        if(bar.state.move_right ){
            bar.shiftRight();
            if(ball.state.launched == false){
                ball.shiftRight();
            }
        }
    if (key == GLFW_KEY_SPACE){
        if(action == GLFW_PRESS){
            if((ball.state.launched == false) && (ball.state.tries < 3)){
                ball.launch();
            }
            
        }
        //if(action == GLFW_RELEASE){
        //}
    }
    if (key == GLFW_KEY_Z){
        if(action == GLFW_PRESS){
            
        }
    }
}


void draw_bricks(){
	// Creates bricks
	for(int i = 0; i < 15; i++){
		if((i >=0) && (i < 15)){
			if(i%2 == 0){
				bricks temp_brick(vec2(i,0), vec3(1, 0, 0));
				all_bricks.push_back(temp_brick);
				all_bricks[i].gl_init();
			}
			if(i%2 != 0){
				bricks temp_brick(vec2(i,-0.75), vec3(0, 1, 0));
				all_bricks.push_back(temp_brick);
				all_bricks[i].gl_init();
			}
		}
	}
	for(int j = 0; j < 15; j++){
		bricks temp_brick(vec2(j,-2.0), vec3(.5, 0, 1));
		all_bricks.push_back(temp_brick);
		all_bricks[j+15].gl_init();
	}
	// Creates gray row of bricks
	for(int j = 0; j < 15; j++){
		bricks temp_brick(vec2(j,-2.5), vec3(.5, .5, .5));
		all_bricks.push_back(temp_brick);
		all_bricks[j+30].gl_init();
		all_bricks[j+30].state.strong=true;
	}
}

void draw_winner(){
	for(int j = 0; j < 10; j++){
		bricks temp_brick(vec2(4,-0.375 * j), vec3(0, 1.0, 1.0));
		all_bricks.push_back(temp_brick);
		all_bricks[j+45].gl_init();
	}
	for(int j = 0; j < 10; j++){
		if(j >=0 && j <2){
			bricks temp_brick(vec2(5,-0.375 * j), vec3(0, 1.0, 1.0));
			all_bricks.push_back(temp_brick);
			all_bricks[j+55].gl_init();
		}
		if(j>=2 && j <4){
			bricks temp_brick(vec2(5,-0.375 * j), vec3(0, 0, 0));
			all_bricks.push_back(temp_brick);
			all_bricks[j+55].gl_init();
		}
		if(j >=4 && j <=5){
			bricks temp_brick(vec2(5,-0.375 * j), vec3(0, 1.0, 1.0));
			all_bricks.push_back(temp_brick);
			all_bricks[j+55].gl_init();
		}
		if(j > 5){
			bricks temp_brick(vec2(5,-0.375 * j), vec3(0, 0, 0));
			all_bricks.push_back(temp_brick);
			all_bricks[j+55].gl_init();
		}
	}
	for(int j = 0; j < 10; j++){
		bricks temp_brick(vec2(7,-0.375 * j), vec3(0, 1.0, 1.0));
		all_bricks.push_back(temp_brick);
		all_bricks[j+65].gl_init();
	}
	for(int j = 0; j < 10; j++){
		bricks temp_brick(vec2(9,-0.375 * j), vec3(0, 1.0, 1.0));
		all_bricks.push_back(temp_brick);
		all_bricks[j+75].gl_init();
	}
	for(int j = 0; j < 9; j++){
		bricks temp_brick(vec2(10+0.2*j,-0.375 * j), vec3(0, 1.0, 1.0));
		all_bricks.push_back(temp_brick);
		all_bricks[j+84].gl_init();
	}
	for(int j = 0; j < 10; j++){
		bricks temp_brick(vec2(11.5,-0.375 * j), vec3(0, 1.0, 1.0));
		all_bricks.push_back(temp_brick);
		all_bricks[j+94].gl_init();
	}
	
}
int hit_brick(vec2 ball_pos){
	if(ball_pos.y<-7.55){
		bar.state.lose=true;
		ball.state.launched=false;
	}
	float brick_h = 0.375;
	float brick_w = 1;
	float ball_w = 0.25/2;
	float ball_height = 0.25/2;
	int num_bricks_hit = 0;

	ball.state.ball_on_brick = false;
	
	for (int i = 0; i < all_bricks.size(); i++){
		
		vec2 cur_brick = all_bricks[i].get_position(0);
		
		if((cur_brick.x <= ball_pos.x + ball_w) && // within left side of brick
		   (cur_brick.x + brick_w >= ball_pos.x - ball_w) && // within right side of brick
		   (cur_brick.y <= ball_pos.y + ball_height) && // within bottom
		   (brick_h + cur_brick.y >= ball_pos.y - ball_height)){ // within top
			ball.state.ball_on_brick = true;
			all_bricks[i].state.hit_count++;
			ball.state.x_i = all_bricks[i].get_position(0).x;
			ball.state.x_f = all_bricks[i].get_position(2).x;
			
		}
		if(all_bricks[i].is_destroyed() == true && ball.state.tries < 3){
			num_bricks_hit+=1;
		}
		if(ball.state.launched==false && ball.state.tries == 3){
			all_bricks[i].state.need_reset=true;
			all_bricks[i].state.brick_hit = false;
			num_bricks_hit = 0;
		}
	}
	return num_bricks_hit;
}
bool all_gone = false;
void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
    bar.gl_init();
    ball.gl_init();
	if(all_gone == true){
		draw_winner();
	}
	else{
		draw_bricks();
	}
	

}
void init_2(){
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
	bar.gl_init();
	ball.gl_init();
	draw_winner();

	
}

//Call update function 30 times a second
void animate(){
    if(glfwGetTime() > 0.033){
        glfwSetTime(0.0);
        bar.update_state();
        ball.update_state();
        for(int i = 0; i < all_bricks.size(); i++){
            all_bricks[i].update_state();
        }
    }
}





int main(void)
{
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_SAMPLES, 10);
    
    
    window = glfwCreateWindow(1024, 1024, "Arkanoid!", NULL, NULL);
    if (!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetKeyCallback(window, key_callback);
    
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);
	
	init();
    while (!glfwWindowShouldClose(window)){
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        
        //Pick a coordinate system that makes the most sense to you
        //(left, right, top, bottom)
        mat4 proj = Ortho2D(-7.55, 7.55, -7.55, 7.55);
        
        ball.reflect(bar.get_bar_vert(1), bar.get_bar_vert(2), bar.get_bar_vert(0), ball.get_ball_vert(0));
		int num = hit_brick(ball.get_ball_vert(0));
		if(num == 45){
			all_gone = true;
			init();
		}
		if(ball.state.tries == 3){
			ball.state.tries = 0;
			num = 0;
		}
		std::cout << num << std::endl;
        animate();
        glClear(GL_COLOR_BUFFER_BIT);
        bar.draw(proj);
        ball.draw(proj);
        for(int i = 0; i < all_bricks.size(); i++){
            all_bricks[i].draw(proj);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
}
