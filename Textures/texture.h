#ifndef TEXTURE_H_
#define TEXTURE_H_ 

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

class Texture
{
public:
	Texture(const std::string& fileName);
	virtual ~Texture();

	void Bind(unsigned int unit);
	
protected:
private:
	Texture(const Texture& other){}
	void operator=(const Texture& other){}

	GLuint m_texture;
};

#endif