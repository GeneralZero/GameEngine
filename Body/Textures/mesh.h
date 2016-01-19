#ifndef MESH_H_
#define MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>
#include "../../easylogging++.h"
#include "../../obj_loader.h"

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0,0,0)){
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}
	~Vertex(){
		
	}

	inline glm::vec3* getPos(){ return &pos; }
	inline glm::vec3* getNormal(){ return &normal; }
	inline glm::vec2* getTexCoord(){ return &texCoord; }
protected:
private:
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 texCoord;
};


class Mesh
{
public:
	Mesh(Vertex* vertexes, unsigned int numVertices, unsigned int* indices, unsigned int numIndexies);
	Mesh(const std::string& fileName);
	Mesh();
	~Mesh();

	void Draw();
	void init(const std::string& fileName);

protected:
private:
	void InitMesh(const IndexedModel& model);
	Mesh(const Mesh& other){}
	void operator=(const Mesh& other){}

	enum{
		POSITION_VB,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];

	unsigned int m_drawCount;
	//unsigned int m_numIndices;
};


#endif