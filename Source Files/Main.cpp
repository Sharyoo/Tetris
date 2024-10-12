#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <vector>

#include "Shader.h"
#include "VBO.h"
#include "VAO.h"
#include "Renderer.h"

#include "Window.h"

#include "Board.h"
#include "Square.h"
#include "Line.h"
#include "LongT.h"
#include "NormalL.h"
#include "NormalZ.h"
#include "ReverseL.h"
#include "ReverseZ.h"

#ifndef SHAPES_H
#define SHAPES_H
#include "Shapes.h"
#endif

#include <random>

std::string vectToStr(std::vector<float> vect) {
	std::string ans{ "{" };
	for (int i = 0; i < vect.size(); i++) {
		ans += std::to_string(vect[i]);
		if (i != vect.size() - 1) ans += ", ";
	}
	ans += "}";
	return ans;
}

std::string vectToStr(std::vector<int> vect) {
	std::string ans{ "{" };
	for (int i = 0; i < vect.size(); i++) {
		ans += std::to_string(vect[i]);
		if (i != vect.size() - 1) ans += ", ";
	}
	ans += "}";
	return ans;
}

std::string get_file_contents(const char* filename);

std::vector<Shapes*> curShape;
int gameOver = 0;

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_S) {
		curShape[0]->moveDown();
	}
	else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		curShape[0]->moveRight();
	}
	else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		curShape[0]->moveLeft();
	}
	else if (key == GLFW_KEY_R && action == GLFW_PRESS) {
		curShape[0]->rotate();
	}
	else if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
		gameOver = 0;
	}

}

int main()
{

	int windowWidth = 700;
	int windowHeight = 1000;
	GLFWwindow* window = createWindow(windowWidth, windowHeight, "Test");

	glfwSetKeyCallback(window, keyCallBack);

	std::vector<float> data{
		0.0f, 0.0f,
		800.0f, 0.0f,
		800.0f, 800.0f
	};

	std::vector<unsigned int> indices{
		0, 1, 2,
		2, 3, 0
	};

	Board board{ 10, 20 };

	VBO boardVBO{};
	VAO boardVAO{};
	Shader shader{ "Source Files/Starter.vert", "Source Files/Starter.frag" };
	shader.Activate();
	boardVAO.Bind();
	boardVBO.SetData(board.corners);
	boardVBO.addData(board.verticalLines);
	boardVBO.addData(board.horizontalLines);
	boardVAO.Link(boardVBO, 2, 5 * sizeof(float));

	VBO squareVBO{};
	VAO squareVAO{};

	squareVAO.Bind();
	squareVBO.Bind();
	squareVAO.Link(squareVBO, 3, 5 * sizeof(float));

	glm::mat4 proj = glm::ortho(0.0f, (float)windowWidth, 0.0f, (float)windowHeight, -1.0f, 1.0f);
	shader.SetUniformMat4f("MVP", proj);

	double curTime{};
	double prevTime{};
	double timeDiff{};
	int counter = 0;

	glfwSwapInterval(0);

	float time = 0;
	float lastTime = 0;
	float timer = 0;
	float coyoteTime = 0;

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 6); // define the range
	int randNum;

	Square sq{ 0, 0, &board.boardMatrix };
	Line l{ 0, 0, &board.boardMatrix };
	LongT lt{ 0, 0, &board.boardMatrix };
	NormalL nl{ 0, 0, &board.boardMatrix };
	NormalZ nz{ 0, 0, &board.boardMatrix };
	ReverseL rl{ 0, 0, &board.boardMatrix };
	ReverseZ rz{ 0, 0, &board.boardMatrix };
	curShape.push_back(&sq);

	randNum = distr(gen);
	if (randNum == 0) {
		sq = { 4, 0, &board.boardMatrix };
		curShape[0] = &sq;
		if (sq.canSpawn()) sq.spawn();
		else gameOver = 1;
	}
	else if (randNum == 1) {
		l = { 3, 0, &board.boardMatrix };
		curShape[0] = &l;
		if (l.canSpawn()) l.spawn();
		else gameOver = 1;

	}
	else if (randNum == 2) {
		lt = { 3, 1, &board.boardMatrix };
		curShape[0] = &lt;
		if (lt.canSpawn()) lt.spawn();
		else gameOver = 1;
	}
	else if (randNum == 3) {
		nl = { 3, 1, &board.boardMatrix };
		curShape[0] = &nl;
		if (nl.canSpawn()) nl.spawn();
		else gameOver = 1;
	}
	else if (randNum == 4) {
		nz = { 3, 0, &board.boardMatrix };
		curShape[0] = &nz;
		if (nz.canSpawn()) nz.spawn();
		else gameOver = 1;
	}
	else if (randNum == 5) {
		rl = { 3, 0, &board.boardMatrix };
		curShape[0] = &rl;
		if (rl.canSpawn()) rl.spawn();
		else gameOver = 1;
	}
	else if (randNum == 6) {
		rz = { 3, 1, &board.boardMatrix };
		curShape[0] = &rz;
		if (rz.canSpawn()) rz.spawn();
		else gameOver = 1;
	}

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		if (!gameOver) {
			time = glfwGetTime();
			timer += time - lastTime;
			if (timer >= 0.5) {
				curShape[0]->moveDown();
				timer = 0;
			}

			if (!curShape[0]->canMoveDown()) {

				coyoteTime += time - lastTime;

				if (coyoteTime >= 0.5f) {

					board.clearAllLines();
					std::cout << "Score: " << board.score << std::endl;

					randNum = distr(gen);

					if (randNum == 0) {
						sq = { 4, 0, &board.boardMatrix };
						curShape[0] = &sq;
						if (sq.canSpawn()) sq.spawn();
						else gameOver = 1;
					}
					else if (randNum == 1) {
						l = { 3, 0, &board.boardMatrix };
						curShape[0] = &l;
						if (l.canSpawn()) l.spawn();
						else gameOver = 1;

					}
					else if (randNum == 2) {
						lt = { 3, 1, &board.boardMatrix };
						curShape[0] = &lt;
						if (lt.canSpawn()) lt.spawn();
						else gameOver = 1;
					}
					else if (randNum == 3) {
						nl = { 3, 1, &board.boardMatrix };
						curShape[0] = &nl;
						if (nl.canSpawn()) nl.spawn();
						else gameOver = 1;
					}
					else if (randNum == 4) {
						nz = { 3, 0, &board.boardMatrix };
						curShape[0] = &nz;
						if (nz.canSpawn()) nz.spawn();
						else gameOver = 1;
					}
					else if (randNum == 5) {
						rl = { 3, 0, &board.boardMatrix };
						curShape[0] = &rl;
						if (rl.canSpawn()) rl.spawn();
						else gameOver = 1;
					}
					else if (randNum == 6) {
						rz = { 3, 1, &board.boardMatrix };
						curShape[0] = &rz;
						if (rz.canSpawn()) rz.spawn();
						else gameOver = 1;
					}

					coyoteTime = 0;
				}
			}
			lastTime = time;

			// Specify the color of the background
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			// Clean the back buffer and assign the new color to it
			glClear(GL_COLOR_BUFFER_BIT);

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glLineWidth(5);

			board.findSquares();
			squareVBO.NewData(board.squares);

			boardVAO.Bind();
			boardVBO.Bind();
			glDrawArrays(GL_LINES, 0, boardVBO.data.size() / 5);

			squareVAO.Bind();
			squareVBO.Bind();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, 0, squareVBO.data.size() / 5);

			glfwSwapBuffers(window);
			// Take care of all GLFW events
			glfwPollEvents();
		}
		else {
			// Specify the color of the background
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			// Clean the back buffer and assign the new color to it
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			// Take care of all GLFW events
			glfwPollEvents();
		}

		curTime = glfwGetTime();
		timeDiff = curTime - prevTime;
		counter++;
		if (timeDiff >= 1 / 30.0) {
			std::string FPS = std::to_string((1.0 / timeDiff) * counter);
			prevTime = curTime;
			counter = 0;
			std::cout << FPS << std::endl;
		}
	}



	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}