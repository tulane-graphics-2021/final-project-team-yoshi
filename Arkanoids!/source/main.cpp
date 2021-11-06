#include "common.h"

using namespace Angel;

Ship ship;
asteroid asteroid;
//std::vector <bullet*> bullets;
bullet bullet;
//bullet bullet/*(vec2 pointing, vec2 velocity ) */;
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
		ship.rotateLeft();
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		ship.rotateRight();

	if (key == GLFW_KEY_SPACE){
		if(action == GLFW_PRESS){
			ship.start_thruster();
			bullet.start_thruster();
			bullet.state.position = ship.state.pointing;
			bullet.state.velocity = ship.state.velocity;
		}
		if(action == GLFW_RELEASE){
			ship.stop_thruster();
			bullet.stop_thruster();
			bullet.state.position = ship.state.pointing;
			bullet.state.velocity = ship.state.velocity;

		}
	}
	if (key == GLFW_KEY_Z){
		if(action == GLFW_PRESS){

			//bullet *bullet = new class bullet(ship.state.pointing, ship.state.velocity);
			//bullets.push_back(bullet);
			//temp.state.position = ship.state.pointing;
			//temp.state.velocity = ship.state.velocity;
			/*vec2 loc = ship.state.pointing;
			vec2 vel = ship.state.velocity;
			for(auto& b: bullets){
				b->state.position += ship.state.pointing;
				b->state.velocity += ship.state.velocity;
			} */
			bullet.pew_pew(ship.state.pointing, ship.state.velocity);
			counter +=1;
			//bullet *bullet;
			//bullet->pew_pew(ship.state.pointing, ship.state.velocity);
			//bullets.push_back(bullet);
			//bullet.state.position = ship.state.pointing;
			//bullet.state.velocity = ship.state.velocity;
		}
	}
}

void init(){
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
	ship.gl_init();
	asteroid.gl_init();
	/*for (int i = 0; i < bullets.size(); i ++){
		bullets[i]->gl_init();
	}*/
	/*for(auto& b: bullets){
		b->gl_init();
	}*/
	bullet.gl_init();
	//bullet.gl_init();
}

//Call update function 30 times a second
void animate(){
	if(glfwGetTime() > 0.033){
		glfwSetTime(0.0);
		ship.update_state();
		asteroid.update_state();
		/*for(int i = 0; i < bullets.size(); i++){
			bullets[i]->update_state();
		}*/
		/*for(auto& b: bullets){
			b->update_state();
		}*/
		bullet.update_state();
		//bullet.update_state();
		asteroid.rotate();
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
	
	
	window = glfwCreateWindow(1024, 768, "Asteroids!", NULL, NULL);
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
		ship.draw(proj);
		asteroid.draw(proj);
		/*for(int i = 0; i < bullets.size(); i ++){
			bullets[i]->draw(proj);
		}*/
		/*for(auto& b: bullets){
			b->draw(proj);  
		} */
		//bullet.draw(proj);
		bullet.draw(proj);
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	}
	
	glfwDestroyWindow(window);
	
	glfwTerminate();
	exit(EXIT_SUCCESS);
	
}
