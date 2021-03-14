#pragma once

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "Log.h"

struct WindowProps {
	std::string title;
	unsigned int width;
	unsigned int height;

	WindowProps(const std::string &p_title = "Learn OpenGL",
				unsigned int p_width = 1280, unsigned int p_height = 1080)
		: title(p_title), width(p_width), height(p_height)
	{
	}
};

class Window {
  public:
	Window(WindowProps p_props = WindowProps());
	~Window();

	static Window *get() { return s_instance; }

	inline GLFWwindow *get_window() { return m_window; }
	inline Renderer &get_renderer() { return *m_renderer; }

  private:
	WindowProps m_props;
	Renderer *m_renderer;
	GLFWwindow *m_window;

	inline static Window *s_instance;
};

#endif // __WINDOW_H__