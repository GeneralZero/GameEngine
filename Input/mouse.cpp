#include "mouse.h"

Mouse::Mouse(){

}

Mouse::~Mouse(){

}


Mouse::doEvent(SDL_EVENT& e){

	//Mouse Event
	if(e.type == SDL_MOUSEMOTION){

	}

	else if(e.type == SDL_MouseButtonEvent){

	}

	else if(e.type == SDL_MouseWheelEvent){

	}
}