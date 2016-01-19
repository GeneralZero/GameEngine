#include "display.h"
#include <iostream>

Display::Display(int width, int height, const std::string& title){
	//Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//Init Window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	m_GLContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();

	if(status != GLEW_OK){
		LOG(ERROR) << "Glew failed to initalize!\n" ;
	}

	is_closed = false;

	/*
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	*/

	glEnable(GL_DEPTH_TEST);

}

Display::~Display(){
	SDL_GL_DeleteContext(m_GLContext);
	SDL_DestroyWindow(m_window);
}

void Display::update(){
	SDL_GL_SwapWindow(m_window);
}

void Display::doEvent(SDL_Event& e){
	if(e.type == SDL_QUIT){
		is_closed = true;
	}
}

void Display::Clear()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Display::isClosed(){
	return is_closed;
}