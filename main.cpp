#include <iostream>
#include <GL/glew.h>
#include "Camera/display.h"
#include "Shaders/shader.h"
#include "Textures/mesh.h"
#include "Textures/texture.h"
#include "Textures/transform.h"
#include "Camera/camera.h"


#define WIDTH 800
#define HEIGHT 600

int main(int argc, char const *argv[])
{
	//Init Display
	Display display(800, 600, "Hello World!");

	//Init Shader
	Shader shader("./res/basicShader");

	//Init Mesh
	Mesh mesh("./res/test.obj");

	//Init Texture
	Texture texture("./res/bricks.jpg");

	//Init Camera
	Camera camera(glm::vec3(0,0,-3), 70.0d, (double)WIDTH/(double)HEIGHT, 0.01d, 1000.0d);

	//Init Keyboard
	Keyboard keyboard();

	//Init Mouse
	Mouse mouse();


	//
	Transform transform;

	float counter = 0.0f;

	while(!display.isClosed()){
		//Clear Display
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		//Input
		SDL_Event e;

		while(SDL_PollEvent(&e)){
			display.doEvent();
			keyboard.doEvent();
			mouse.doEvent();
		}

		float sinCounter = sinf(counter);
		//float absSinCounter = abs(sinCounter);
		transform.GetPos()->x = sinCounter;
		transform.GetRot()->y = counter * 100;
		transform.GetRot()->z = counter * 100;
		//transform.GetScale()->x = absSinCounter;
		//transform.GetScale()->y = absSinCounter;

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();



		//Redraw
		display.update();
		counter += 0.0001f;
	}


	SDL_Quit();
	return 0;
}