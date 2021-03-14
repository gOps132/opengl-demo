#include "Window.h"

#include <imgui.h>
#include <examples/imgui_impl_opengl3.h>
#include <examples/imgui_impl_glfw.h>

#include "Renderer.h"
#include "ErrorManager.h"
#include "Log.h"

Window::Window(WindowProps p_props)
	: m_props(p_props)
{
	CORE_ASSERT(!s_instance, "Application already exists!");
	s_instance = this;

	Log::init();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	m_window = glfwCreateWindow(p_props.height, p_props.width,
								p_props.title.c_str(), NULL, NULL);

	if (m_window == NULL) {
		LOG_CORE_ERROR("Failed to create GLFW m_window");
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_window);

	glfwSwapInterval(1); // synchronize with our vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG_CORE_ERROR("Failed to initialize GLAD");
	}

	glViewport(0, 0, p_props.height, p_props.width);

	glfwSetFramebufferSizeCallback(
		m_window, [](GLFWwindow *window, int width, int height) {
			GLCall(glViewport(0, 0, width, height));
		});

	const char *glsl_version = "#version 330 core";

	/* ImGui Initialization */
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

Window::~Window()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();

	ImGui::DestroyContext();

	glfwTerminate();
}
