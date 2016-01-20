#ifndef BODY_H_
#define BODY_H_ 

#include <string>
#include "../easylogging++.h"
#include "../Camera/display.h"
#include "Shaders/shader.h"
#include "Textures/mesh.h"
#include "Textures/texture.h"
#include "Textures/transform.h"
#include "../Camera/camera.h"

class Body
{
private:
	float counter;
	Camera* camera;

public:
	Body(const std::string& shaderFilename, const std::string& meshFilename, const std::string& textureFilename, Camera* camera);
	~Body();

	void update();

	Shader shader;
	Mesh mesh;
	Texture texture;

	Transform transform;
};





#endif