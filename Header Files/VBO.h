#pragma once

#include <vector>
#include<glad/glad.h>

class VBO {
public:
	unsigned int id;
	int numVerts{};

	std::vector<float> data{};

	VBO();
	void SetData(std::vector<float> data);
	void NewData(std::vector<float> data);
	void addData(std::vector<float> data);
	void Bind();
	void Unbind();
	void Delete();
};