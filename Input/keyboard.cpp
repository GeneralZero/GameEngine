#include "keyboard.h"
#include <GL/glut.h>


Keyboard::Keyboard(){

}

Keyboard::~Keyboard(){

}

void Keyboard::doEvent(SDL_Event& e){
	//Update Keys
	if (e.type == SDL_KEYDOWN){
		keyboardState[e.key.keysym.sym] = true;

		//Newly Pressed Keys
		if( prevKeyboardState.find(e.key.keysym.sym) == prevKeyboardState.end()){
			LOG(INFO) << "Newly Pressed: " << e.key.keysym.sym;

			prevKeyboardState.insert(std::pair<uint,bool>(e.key.keysym.sym, true));
		}
		//Held Keys
		else{

		}

		//reset Keyboard state
	}
	else if(e.type == SDL_KEYUP){
		LOG(INFO) << "Releaced Keys: " << e.key.keysym.sym;

		//reset Keyboard state
		prevKeyboardState.erase(e.key.keysym.sym);

	}
}