#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "glm/gtc/matrix_transform.hpp"
#include "../easylogging++.h"

class Camera
{
public:
	Camera(const glm::vec3& pos, double fov, double aspect, double zNear, double zFar);
	~Camera();

	glm::mat4 GetViewProjection();

	void moveFoward();
	void moveRight();
	void moveLeft();
	void moveReverse();
	void moveUp();
	void moveDown();


	void lookUp();
	void lookDown();
	void lookRight();
	void lookLeft();

protected:
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_foward;
	glm::vec3 m_up;

};


#endif