#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard {
	private:

	public:
		std::map<uint, bool> prevKeyboardState;
		std::map<uint, bool> keyboardState;

		doEvent(SDL_EVENT& e);

		Keyboard();
		~Keyboard();
	
};

#endif