#include "IBO.h"

IBO::IBO() {
	//glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &id);
	glGenBuffers(1, &id);
}

IBO::IBO(std::vector<unsigned int> indices) {
	glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &id);
	this->indices = indices;
	this->count = indices.size();
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
	Unbind();
}

void IBO::SetIndices(std::vector<unsigned int> indices) {
	this->indices = indices;
	this->count = indices.size();
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
	Unbind();
}

void IBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}