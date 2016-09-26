#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include<iostream>
using namespace std;

const int width = 1100;
const int height = 680;

float* pixels = new float[width*height * 3];


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 != i1)
	{
		for (int i = i0; i <= i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawPixel(i, j, red, green, blue);
		}
	}
	else
	{
		for (int k = j0; k < j1; k++)
			drawPixel(i0, k, 0.0f, 0.0f, 0.0f);
	}
}

void drawCircle(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
{
	for (int a = i - r; a < i + r; a++)
	{
		for (int b = j - r; b < j + r; b++)
		{
			//원의 방정식 이용
			int c = ((a - i)*(a - i) + (b - j)*(b - j) - (r - 1)*(r - 1));
			int d = ((a - i)*(a - i) + (b - j)*(b - j) - r * r);

			if (c > 0 && d < 0)
				drawPixel(a, b, red, green, blue);
		}
	}


}
void drawOnPixelBuffer(GLFWwindow *window)
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background


	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	//squre
	drawLine(100, 450, 150, 450, 0.0f, 0.0f, 0.0f);
	drawLine(100, 500, 150, 500, 0.0f, 0.0f, 0.0f);
	drawLine(100, 450, 100, 500, 0.0f, 0.0f, 0.0f);
	drawLine(150, 450, 150, 500, 0.0f, 0.0f, 0.0f);
	drawCircle(125, 475, 60, 0.0f, 0.0f, 1.0f);

	int r = 60;
	double xpos, ypos;

	glfwGetCursorPos(window, &xpos, &ypos);
	double f = (xpos - 125)*(xpos - 125) + (ypos - 205)*(ypos - 205) - 60 * 60;

	if (f <= 0.0)
		drawCircle(125, 475, 60, 1.0f, 0.0f, 0.0f);


	//line
	for (int x = 1; x < 8; x++)
	{
		drawLine(300, 450 + x, 350, 500 + x, 0.0f, 0.0f, 0.0f);
	}
	drawCircle(325, 475, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 325)*(xpos - 325) + (ypos - 205)*(ypos - 205) - 60 * 60;

	if (f <= 0.0)
		drawCircle(325, 475, 60, 1.0f, 0.0f, 0.0f);


	//circle
	drawCircle(530, 470, 27, 0.0f, 0.0f, 0.0f);
	drawCircle(530, 470, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 530)*(xpos - 530) + (ypos - 205)*(ypos - 205) - 60 * 60;

	if (f <= 0.0)
		drawCircle(530, 470, 60, 1.0f, 0.0f, 0.0f);


	//x
	for (int x = 1; x < 6; x++)
	{
		drawLine(700, 450 + x, 750, 500 + x, 0.0f, 0.0f, 0.0f);
		drawLine(700, 500 + x, 750, 450 + x, 0.0f, 0.0f, 0.0f);
	}
	drawCircle(725, 475, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 725)*(xpos - 725) + (ypos - 205)*(ypos - 205) - 60 * 60;

	if (f <= 0.0)
		drawCircle(725, 475, 60, 1.0f, 0.0f, 0.0f);


	//↓
	drawLine(900, 447, 900, 510, 0.0f, 0.0f, 0.0f);
	drawLine(880, 465, 900, 445, 0.0f, 0.0f, 0.0f);
	drawLine(900, 445, 920, 465, 0.0f, 0.0f, 0.0f);
	drawCircle(900, 475, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 900)*(xpos - 900) + (ypos - 205)*(ypos - 205) - 60 * 60;

	if (f <= 0.0)
		drawCircle(900, 475, 60, 1.0f, 0.0f, 0.0f);


	//→
	drawLine(100, 200, 163, 200, 0.0f, 0.0f, 0.0f);
	drawLine(143, 220, 163, 200, 0.0f, 0.0f, 0.0f);
	drawLine(143, 180, 163, 200, 0.0f, 0.0f, 0.0f);
	drawCircle(130, 200, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 130)*(xpos - 130) + (ypos - 480)*(ypos - 480) - 60 * 60;

	if (f <= 0.0)
		drawCircle(130, 200, 60, 1.0f, 0.0f, 0.0f);


	//A
	for (int x = 1; x < 3; x++)
	{
		drawLine(305, 170 + x, 335, 230 + x, 0.0f, 0.0f, 0.0f);
		drawLine(335, 230 + x, 365, 170 + x, 0.0f, 0.0f, 0.0f);
	}
	drawLine(320, 200, 350, 200, 0.0f, 0.0f, 0.0f);
	drawCircle(335, 200, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 335)*(xpos - 335) + (ypos - 480)*(ypos - 480) - 60 * 60;

	if (f <= 0.0)
		drawCircle(335, 200, 60, 1.0f, 0.0f, 0.0f);


	//│
	drawLine(530, 170, 530, 230, 0.0f, 0.0f, 0.0f);
	drawCircle(530, 200, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 530)*(xpos - 530) + (ypos - 480)*(ypos - 480) - 60 * 60;

	if (f <= 0.0)
		drawCircle(530, 200, 60, 1.0f, 0.0f, 0.0f);


	//←
	drawLine(700, 200, 763, 200, 0.0f, 0.0f, 0.0f);
	drawLine(700, 200, 720, 220, 0.0f, 0.0f, 0.0f);
	drawLine(700, 200, 720, 180, 0.0f, 0.0f, 0.0f);
	drawCircle(730, 200, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 730)*(xpos - 730) + (ypos - 480)*(ypos - 480) - 60 * 60;

	if (f <= 0.0)
		drawCircle(730, 200, 60, 1.0f, 0.0f, 0.0f);


	//↑
	drawLine(900, 170, 900, 230, 0.0f, 0.0f, 0.0f);
	drawLine(880, 210, 900, 230, 0.0f, 0.0f, 0.0f);
	drawLine(900, 230, 920, 210, 0.0f, 0.0f, 0.0f);
	drawCircle(900, 200, 60, 0.0f, 0.0f, 1.0f);

	glfwGetCursorPos(window, &xpos, &ypos);
	f = (xpos - 900)*(xpos - 900) + (ypos - 480)*(ypos -480) - 60 * 60;

	if (f <= 0.0)
		drawCircle(900, 200, 60, 1.0f, 0.0f, 0.0f);
}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer(window);

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}


