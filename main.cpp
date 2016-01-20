#include <iostream>
#include <thread>
#include <GL/glew.h>
#include "Input/keyboard.h"
#include "Input/mouse.h"
#include "Body/body.h"
#include "Camera/display.h"

INITIALIZE_EASYLOGGINGPP

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char const *argv[])
{
	//Init Display
	Display display(800, 600, "Hello World!");

	//Init Body
	Body body("./res/basicShader", "./res/test.obj", "./res/bricks.jpg");

	//Init Camera
	Camera camera(glm::vec3(0,0,-3), 70.0d, (double)WIDTH/(double)HEIGHT, 0.01d, 1000.0d);

	//Init Keyboard
	Keyboard keyboard(&display, &camera);

	//Init Mouse
	//Mouse mouse(display&, camera&);

	while(!display.isClosed()){
		//Clear Display
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		//Input
		SDL_Event e;

		while(SDL_PollEvent(&e)){
			display.doEvent(e);
			keyboard.doEvent(e);
			//mouse.doEvent(e, &camera);
		}

		body.update(camera);

		//Redraw
		display.update();
	}

	SDL_Quit();
	return 0;
}