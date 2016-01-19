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
	}
	else if(e.type == SDL_KEYUP){
		keyboardState[e.key.keysym.sym] = false;
	}

	//Deal with New and Held Keys
	for(std::map<uint, bool>::iterator iterator = keyboardState.begin(); iterator != keyboardState.end(); iterator++) {
		
		//Newly Pressed Keys
		if( prevKeyboardState[iterator->first] == false){

		}
		//Held Keys
		else{

		}
	}

	for(std::map<uint, bool>::iterator iterator = prevKeyboardState.begin(); iterator != prevKeyboardState.end(); iterator++) {
		
		//Deal with Releaced Keys
		if(keyboardState[iterator->first] == false){

		}
	}

	//reset Keyboard state
	prevKeyboardState.clear();
	prevKeyboardState = keyboardState;
	keyboardState.clear();

}