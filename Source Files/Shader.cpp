#include "Shader.h"

std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {

	id = glCreateProgram();

	std::string vertexCode = get_file_contents(vertexFile);
	const char* vertexSource = vertexCode.c_str();
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	std::string fragmentCode = get_file_contents(fragmentFile);
	const char* fragmentSource = fragmentCode.c_str();
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate() {
	glUseProgram(id);
}

void Shader::Delete() {
	glDeleteProgram(id);
}

int Shader::GetUniformLocation(const std::string& name) {
	int location = glGetUniformLocation(id, name.c_str());
	return location;
}

void Shader::SetUniform4f(const std::string& name, float v1, float v2, float v3, float v4) {
	glUniform4f(GetUniformLocation(name), v1, v2, v3, v4);
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix) {
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}