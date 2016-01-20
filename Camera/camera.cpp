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

void Camera::moveFoward(double inc){
	m_position += (float)inc * m_foward;
}

void Camera::moveRight(double inc){
	m_position += (float)inc * glm::cross(m_foward, m_up);
}

void Camera::moveLeft(double inc){
	m_position -= (float)inc * glm::cross(m_foward, m_up);
}

void Camera::moveReverse(double inc){
	m_position -= (float)inc * m_foward;
}

void Camera::moveUp(double inc){
	m_position += (float)inc * m_up;
}

void Camera::moveDown(double inc){
	m_position -= (float)inc * m_up;
}


void Camera::look(int x, int y, float inc){

	//Rotate x
	m_foward = glm::mat3(glm::rotate(-x * inc, m_up)) * m_foward;

	//Rotate y
	m_foward = glm::mat3(glm::rotate(-y * inc, glm::cross(m_foward, m_up))) * m_foward;
	
}

Camera::~Camera(){

}