#ifndef CAMERA_H_
#define CAMERA_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Camera
{
public:
	Camera(const glm::vec3& pos, double fov, double aspect, double zNear, double zFar){
		m_perspective = glm::perspective((float)fov, (float)aspect, (float)zNear, (float)zFar);
		m_position = pos;
		m_foward = glm::vec3(0,0,1);
		m_up = glm::vec3(0,1,0);
	}

	inline glm::mat4 GetViewProjection() const{
		return m_perspective * glm::lookAt(m_position, m_position + m_foward, m_up);
	}
	~Camera(){

	}
protected:
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_foward;
	glm::vec3 m_up;

};


#endif