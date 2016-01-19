#include "mesh.h"
#include <vector>

Mesh::Mesh(const std::string& fileName){
	InitMesh(OBJModel(fileName).ToIndexedModel());
}

void Mesh::InitMesh(const IndexedModel& model){

	m_drawCount = model.indices.size();

	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);


	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);


	glBindVertexArray(0);
}

Mesh::Mesh(Vertex* vertexes, unsigned int numVertices, unsigned int* indices, unsigned int numIndexies){

	IndexedModel model;

	for (unsigned int i = 0; i < numVertices; ++i)
	{
		model.positions.push_back(*vertexes[i].getPos());
		model.texCoords.push_back(*vertexes[i].getTexCoord());
		model.normals.push_back(*vertexes[i].getNormal());
	}

	for (unsigned int i = 0; i < numIndexies; ++i)
	{
		model.indices.push_back(indices[i]);
	}

	InitMesh(model);

/*
	//m_drawCount = numVertices;
	m_drawCount = numIndexies;

	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve(numVertices);
	positions.reserve(numVertices);

	for (unsigned int i = 0; i < numVertices; ++i)
	{
		positions.push_back(*vertexes[i].getPos());
		texCoords.push_back(*vertexes[i].getTexCoord());
	}

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXTCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndexies*sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
*/
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw(){
	glBindVertexArray(m_vertexArrayObject);

	//glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}