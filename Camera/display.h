#ifndef DISPLAY_H_
#define DISPLAY_H_ 

#include <SDL2/SDL.h>
#include <string>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	void update();
	bool isClosed();
	void Clear(float a, float b, float c, float d);
	void Clear();

protected:
private:
	Display(const Display& other) {}
	void operator=(const Display& other) {}

	SDL_Window* m_window;
	SDL_GLContext m_GLContext;
	bool is_closed;
	
};

#endif