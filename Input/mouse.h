#ifndef MOUSE_H_
#define MOUSE_H_

#include <map>
#include <SDL2/SDL.h>
#include "../Camera/camera.h"
#include "../Camera/display.h"
#include "../easylogging++.h"

class Mouse {
	private:


	public:
		Mouse();
		//Mouse(display&, camera&);
		~Mouse();

		void doEvent(SDL_Event& e);

		void ResetMouseLocation();
	
};

#endif