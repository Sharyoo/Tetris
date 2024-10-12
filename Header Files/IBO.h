#pragma once

#include <vector>
#include<glad/glad.h>

class IBO {
public:
	std::vector<unsigned int> indices;
	unsigned int id;
	unsigned int count;

	IBO();
	IBO(std::vector<unsigned int> indices);
	void SetIndices(std::vector<unsigned int> indices);
	void Bind();
	void Unbind();
};