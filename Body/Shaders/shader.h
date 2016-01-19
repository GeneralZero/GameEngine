#ifndef SHADER_H_
#define SHADER_H_ 

#include <string>
#include <GL/glew.h>
#include "../../easylogging++.h"
#include "../Textures/transform.h"
#include "../../Camera/camera.h"

class Shader
{
public:
	Shader(const std::string& filename);
	Shader();


	GLuint CreateShader(const std::string& text, unsigned int type);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	std::string LoadShader(const std::string& fileName);
	void Bind();
	void Update(const Transform& transform, const Camera& camera);
	void init(const std::string& fileName);

	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;

	Shader(const Shader& other) {}
	void operator=(const Shader& other){}

	enum 
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

#endif