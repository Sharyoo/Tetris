#include "Renderer.h"

Renderer::Renderer() {}

void Renderer::drawTriangles(std::vector<float> tris, int numAttribs, int sizeOfAttribs) {
	shader.Activate();
	vao.Bind();
	vbo.SetData(tris);
	vao.Link(vbo, numAttribs, sizeOfAttribs);
	glDrawArrays(GL_TRIANGLES, 0, vao.numVerts);
}

void Renderer::drawTrianglesIBO(std::vector<float> tris, std::vector<unsigned int> indices, int numAttribs, int sizeOfAttribs) {
	shader.Activate();
	vao.Bind();
	vbo.SetData(tris);
	vao.Link(vbo, numAttribs, sizeOfAttribs);
	ibo.SetIndices(indices);
	ibo.Bind();
	glDrawElements(GL_TRIANGLES, ibo.count, GL_UNSIGNED_INT, nullptr);
}