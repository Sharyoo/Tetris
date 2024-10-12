#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &id);
}

void VAO::Link(VBO& vbo, int numAttribs, int sizeOfAttribs) {
	vbo.Bind();
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	numVerts = vbo.numVerts;
	vbo.Unbind();
}

void VAO::Bind() {
	glBindVertexArray(id);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &id);
}