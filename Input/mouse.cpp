#include "mouse.h"

Mouse::Mouse(){

}

Mouse::~Mouse(){

}


void Mouse::doEvent(SDL_Event& e){

	//Mouse Event
	if(e.type == SDL_MOUSEMOTION){

		//Save old X and Y
		//LOG(INFO) << "Mouse Move (x=" << e.motion.xrel << ",y=" << e.motion.yrel << ")\n";
	}

	else if(e.type == SDL_MOUSEBUTTONDOWN){
		LOG(INFO) << "Mouse Click (" << (uint)(e.button.button) << ",x=" << e.button.x << ",y=" << e.button.y << ")";
	}

	else if(e.type == SDL_MOUSEBUTTONUP){
		LOG(INFO) << "Mouse UP (" << (uint)(e.button.button) << ",x=" << e.button.x << ",y=" << e.button.y << ")";
	}

	else if(e.type == SDL_MOUSEWHEEL){
		LOG(INFO) << "Mouse Wheel (x=" << e.wheel.x << ",y=" << e.wheel.y << ")";
	}
}