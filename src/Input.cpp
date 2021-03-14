#include "Input.h"
#include "Window.h"

bool Input::key_pressed(int keycode)
{
	auto window = static_cast<GLFWwindow *>(Window::get_window());
	auto state = glfwGetKey(window, keycode);

	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::mouse_btn_pressed(int button)
{
	auto window = static_cast<GLFWwindow *>(Window::get_window());
	auto state = glfwGetMouseButton(window, button);

	return state == GLFW_PRESS;
}

std::pair<float, float> Input::get_mouse_pos()
{
	auto window = static_cast<GLFWwindow *>(Window::get_window());
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);

	return {(float)xPos, (float)yPos};
}

float Input::get_mouse_x()
{
	auto [x, y] = get_mouse_pos();
	return x;
}

float Input::get_mouse_y()
{
	auto [x, y] = get_mouse_pos();
	return y;
}