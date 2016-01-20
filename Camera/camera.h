#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "../easylogging++.h"

class Camera
{
public:
	Camera(const glm::vec3& pos, double fov, double aspect, double zNear, double zFar);
	~Camera();

	glm::mat4 GetViewProjection();

	void moveFoward(double inc);
	void moveRight(double inc);
	void moveLeft(double inc);
	void moveReverse(double inc);
	void moveUp(double inc);
	void moveDown(double inc);


	void look(int x, int y, float inc);

protected:
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_foward;
	glm::vec3 m_up;

};


#endif