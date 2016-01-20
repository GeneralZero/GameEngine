#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <map>
#include <SDL2/SDL.h>
#include "../Camera/display.h"
#include "../Camera/camera.h"
#include <GL/glut.h>
#include "../easylogging++.h"

class Keyboard {
	private:
		Display* display;
		Camera* camera;


	public:
		std::map<uint, bool> prevKeyboardState;
		std::map<uint, bool> keyboardState;

		void doEvent(SDL_Event& e);

		Keyboard();
		Keyboard(Display* display, Camera* camera);
		~Keyboard();
	
};

#endif