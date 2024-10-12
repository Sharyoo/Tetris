#include "VBO.h"
#include <iostream>

VBO::VBO() {
	glGenBuffers(1, &id);
}

std::string vectToStr(std::vector<float> vect);

std::vector<float> appendVector(std::vector<float> v1, std::vector<float> v2) {
	for (int i = 0; i < v2.size(); i++) {
		v1.push_back(v2[i]);
	}
	return v1;
}

void VBO::SetData(std::vector<float> data) {
	this->data = appendVector(this->data, data);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, this->data.size() * sizeof(float), this->data.data(), GL_STATIC_DRAW);
}

void VBO::NewData(std::vector<float> data) {
	this->data = data;
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, this->data.size() * sizeof(float), this->data.data(), GL_STATIC_DRAW);
}

void VBO::addData(std::vector<float> data) {
	SetData(data);
}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	glDeleteBuffers(1, &id);
}