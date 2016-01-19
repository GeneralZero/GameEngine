#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <map>
#include <SDL2/SDL.h>
#include "../easylogging++.h"

class Keyboard {
	private:

	public:
		std::map<uint, bool> prevKeyboardState;
		std::map<uint, bool> keyboardState;

		void doEvent(SDL_Event& e);

		Keyboard();
		~Keyboard();
	
};

#endif