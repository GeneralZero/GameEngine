#include "keyboard.h"


Keyboard::Keyboard(){

}

Keyboard::Keyboard(Display* g_display, Camera* g_camera){
	display = g_display;
	camera = g_camera;
}

Keyboard::~Keyboard(){

}

void Keyboard::doEvent(SDL_Event& e){
	//Update Keys
	if (e.type == SDL_KEYDOWN){
		keyboardState[e.key.keysym.sym] = true;

		switch(e.key.keysym.sym){
			case SDLK_w:
				camera->moveFoward(0.1f);
				break;

			case SDLK_a:
				camera->moveLeft(0.1f);
				break;

			case SDLK_s:
				camera->moveReverse(0.1f);
				break;
			
			case SDLK_d:
				camera->moveRight(0.1f);
				break;
			
			case SDLK_r:
				camera->moveUp(0.1f);
				break;
			
			case SDLK_f:
				camera->moveDown(0.1f);
				break;
		}

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

		//If Exc quit
		if(e.key.keysym.sym == SDLK_ESCAPE){
			display->quit();
		}


		//reset Keyboard state
		prevKeyboardState.erase(e.key.keysym.sym);

	}
}