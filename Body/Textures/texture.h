#ifndef TEXTURE_H_
#define TEXTURE_H_ 

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include "../../easylogging++.h"

class Texture
{
public:
	Texture();
	Texture(const std::string& fileName);
	virtual ~Texture();

	void Bind(unsigned int unit);
	void init(const std::string& fileName);
	
protected:
private:
	Texture(const Texture& other){}
	void operator=(const Texture& other){}

	GLuint m_texture;
};

#endif