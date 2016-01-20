#include "camera.h"



Camera::Camera(const glm::vec3& pos, double fov, double aspect, double zNear, double zFar){
	m_perspective = glm::perspective((float)fov, (float)aspect, (float)zNear, (float)zFar);
	m_position = pos;
	m_foward = glm::vec3(0,0,1);
	m_up = glm::vec3(0,1,0);
}

glm::mat4 Camera::GetViewProjection(){
	return m_perspective * glm::lookAt(m_position, m_position + m_foward, m_up);
}

void Camera::moveFoward(){
	m_position += .1f * m_foward;
}

void Camera::moveRight(){
	m_position += .1f * glm::cross(m_foward, m_up);
}

void Camera::moveLeft(){
	m_position -= .1f * glm::cross(m_foward, m_up);
}

void Camera::moveReverse(){
	m_position -= .1f * m_foward;
}

void Camera::moveUp(){
	m_position += .1f * m_up;
}

void Camera::moveDown(){
	m_position -= .1f * m_up;
}

/*
void Camera::lookUp(){
	m_position +=
}
void Camera::lookDown(){
	m_position +=
}
void Camera::lookRight(){
	m_position +=
}
void Camera::lookLeft(){
	m_position +=
}
*/
Camera::~Camera(){

}