#pragma once

#include <string>
#include<fstream>
#include<sstream>
#include<cerrno>
#include<glad/glad.h>
#include<glm/glm.hpp>
#include<iostream>

class Shader {
public:
	GLuint id;

	Shader(const char* vertexFile, const char* fragmentFile);
	void Activate();
	void Delete();

	int GetUniformLocation(const std::string& name);
	void SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
};