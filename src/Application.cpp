/*
 *
 *   Made by Epilan Gian Cedrick G.
 *   Most code by https://learnopengl.com, and the cherno
 * https://youtube.com/thecherno
 *
 * 	TODO: implement some kind of break point trap for every compiler
 * 	TODO: make some kind of manifest for xcode settings, compilers in order
 * for the code to run right
 * 	TODO: make a glfw window context that handles the window data ( height,
 * width, etc.. )
 *
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>
#include <examples/imgui_impl_opengl3.h>
#include <examples/imgui_impl_glfw.h>

#include "Window.h"
#include "Log.h"
#include "Renderer.h"
#include "ErrorManager.h"
#include "VertexBufferLayout.h"

#include "Input.h"

#include "Test.h"

#include "test/test_clear_color/TestClearColor.h"
#include "test/test_texture_2d/TestTexture2d.h"
#include "test/video_rendering/video_rendering.h"
#include "test/test_3d_cube/test_3d_cube.h"
#include "test/test_polygons/test_polygons.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	GLCall(glViewport(0, 0, width, height));
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(void)
{
	Log::init();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	constexpr int m_height = 1080;
	constexpr int m_width = 720;
	
	
	Window window(glfwCreateWindow(m_height, m_width, "LearnOpenGL", NULL, NULL));

	if (Window::get_window() == NULL) {
		std::cout << "Failed to create GLFW Window::get_window()" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(Window::get_window());

	glfwSwapInterval(1); // synchronize with our vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, m_height, m_width);

	glfwSetFramebufferSizeCallback(Window::get_window(), framebuffer_size_callback);

	Renderer renderer;

	const char *glsl_version = "#version 330 core";

	/* ImGui Initialization */
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(Window::get_window(), true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	test::Test *currentTest = nullptr;
	test::TestMenu *testMenu = new test::TestMenu(currentTest);
	currentTest = testMenu;

	testMenu->RegisterTest<test::TestClearColor>("Clear Color");
	testMenu->RegisterTest<test::TestTexture2d>("Texture 2d");
	testMenu->RegisterTest<test::video_rendering>("Video Rendering");
	testMenu->RegisterTest<test::test_3d_cube>("3d Cube");
	testMenu->RegisterTest<test::test_polygons>("Other Random Polygons");

	while (!glfwWindowShouldClose(Window::get_window())) {
		/* resets to black at the menu */
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));

		processInput(Window::get_window());

		renderer.Clear();

		/* new imgui frame */
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (currentTest) {
			currentTest->OnUpdate(0.0f);
			currentTest->OnRender();
			ImGui::Begin("Test");
			if (currentTest != testMenu && ImGui::Button("<-")) {
				delete currentTest;
				currentTest = testMenu;
			}
			currentTest->ImGuiRender();
			ImGui::End();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(Window::get_window());
		glfwPollEvents();
	}

	delete currentTest;
	if (currentTest != testMenu)
		delete testMenu;

	/* ImGUI shutdown */
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();

	ImGui::DestroyContext();

	glfwTerminate();

	return 0;
}