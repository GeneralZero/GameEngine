#include "mouse.h"

Mouse::Mouse(){

}

Mouse::Mouse(Display* g_display, Camera* g_camera){
	display = g_display;
	camera = g_camera;
}

Mouse::~Mouse(){

}


void Mouse::doEvent(SDL_Event& e){

	//Mouse Event
	if(e.type == SDL_MOUSEMOTION){

		if(e.motion.state == 1){
			camera->look(e.motion.xrel, e.motion.yrel, 0.01f);
		}

		

		//Save old X and Y
		//LOG(INFO) << "Mouse Move (" << e.motion.state << "x=" << e.motion.xrel << ",y=" << e.motion.yrel << ")";
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