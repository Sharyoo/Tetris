#pragma once

#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "IBO.h"
#include <vector>
#include <iostream>

class Renderer {
public:
	Shader shader{ "default.vert", "default.frag" };
	VBO vbo{};
	VAO vao{};
	IBO ibo{};

	Renderer();
	void drawTriangles(std::vector<float> tris, int numAttribs, int sizeOfAttribs);
	void drawTrianglesIBO(std::vector<float> tris, std::vector<unsigned int> indices, int numAttribs, int sizeOfAttribs);
};