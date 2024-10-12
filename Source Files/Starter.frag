#version 330 core

in vec4 FragColor;
out vec4 color;

uniform vec4 testColor;

void main()
{
   color = FragColor;
};