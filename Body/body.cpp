#include "body.h"


Body::Body(const std::string& shaderFilename, const std::string& meshFilename, const std::string& textureFilename, Camera* g_camera){
	
	//Init Shader
	shader.init(shaderFilename);

	//Init Mesh
	mesh.init(meshFilename);

	//Init Texture
	texture.init(textureFilename);

	camera = g_camera;

	counter = 0.0f;
}

Body::~Body(){

}

void Body::update(){
	

	float sinCounter = sinf(counter);
	//float absSinCounter = abs(sinCounter);
	transform.GetPos()->x = sinCounter;
	transform.GetRot()->y = counter * 100;
	transform.GetRot()->z = counter * 100;
	//transform.GetScale()->x = absSinCounter;
	//transform.GetScale()->y = absSinCounter;

	counter += 0.0001f;

	shader.Bind();
	texture.Bind(0);
	shader.Update(transform, camera);
	mesh.Draw();
}