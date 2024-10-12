#pragma once

#include<glad/glad.h>
#include "VBO.h"

class VAO {
public:
	unsigned int id;
	int numVerts{};

	VAO();
	void Link(VBO& vbo, int numAttribs, int sizeOfAttribs);
	void Bind();
	void Unbind();
	void Delete();
};