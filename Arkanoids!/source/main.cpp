#include "common.h"

using namespace Angel;

bar bar;
ball ball;
bricks bricks;
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
		}
	
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		if(bar.state.move_right){
			bar.shiftRight();
		}
	if (key == GLFW_KEY_SPACE){
		if(action == GLFW_PRESS){
			
		}
		if(action == GLFW_RELEASE){
			

		}
	}
	if (key == GLFW_KEY_Z){
		if(action == GLFW_PRESS){
			
		}
	}
}

void init(){
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
	bar.gl_init();
	ball.gl_init();
	bricks.gl_init();
}

//Call update function 30 times a second
void animate(){
	if(glfwGetTime() > 0.033){
		glfwSetTime(0.0);
		bar.update_state();
		ball.update_state();
		bricks.update_state();
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
	
	
	window = glfwCreateWindow(1024, 768, "Arkanoid!", NULL, NULL);
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
		mat4 proj = Ortho2D(-1.0, 1.0, -1.0, 1.0);
		
		animate();
		
		glClear(GL_COLOR_BUFFER_BIT);
		bar.draw(proj);
		ball.draw(proj);
		bricks.draw(proj);
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	}
	
	glfwDestroyWindow(window);
	
	glfwTerminate();
	exit(EXIT_SUCCESS);
	
}
