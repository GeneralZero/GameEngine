#include <GL/glut.h>


Keyboard::Keyboard(){

}

Keyboard::~Keyboard(){

}

uint Keyboard::doEvents(SDL_Event e){

	//Update Keys
	if (e.type == SDL_KEYDOWN){
		keyboardState[event.key.keysym.sym] = true;
	}
	else if(e.type == SDL_KEYUP){
		keyboardState[event.key.keysym.sym] = false;
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

	for(std::map<uint, bool>::iterator iterator = prevkeyboardState.begin(); iterator != prevkeyboardState.end(); iterator++) {
		
		//Deal with Releaced Keys
		if(KeyboardState[iterator->first] == false){

		}
	}

	//reset Keyboard state
	prevkeyboardState.clear();
	prevkeyboardState = keyboardState;
	keyboardState.clear();

}