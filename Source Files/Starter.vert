#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;

uniform mat4 MVP;

out vec4 FragColor;

void main()
{
	gl_Position = MVP * vec4(aPos, 1.0f);
	FragColor = vec4(color, 1.0f);
};