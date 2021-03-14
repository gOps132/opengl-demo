#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <GLFW/glfw3.h>

struct WindowProps {
	std::string title;
	unsigned int width;
	unsigned int height;

	WindowProps(const std::string &p_title = "Learn OpenGL",
				unsigned int p_width = 1280, unsigned int p_height = 720)
		: title(p_title), width(p_width), height(p_height)
	{
	}
};

class Window
{	
public:
	Window(GLFWwindow* p_window) : glfw_window(p_window)
	{
		
	}

	Window get() { return s_window; }

	inline GLFWwindow* get_window() { return glfw_window; }
private:
	GLFWwindow* glfw_window;
	inline static Window* s_window;
};

#endif // __APPLICATION_H__