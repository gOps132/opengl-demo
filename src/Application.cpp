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

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(void)
{
	Window* s_window = new Window();

	test::Test *currentTest = nullptr;
	test::TestMenu *testMenu = new test::TestMenu(currentTest);
	currentTest = testMenu;

	testMenu->RegisterTest<test::TestClearColor>("Clear Color");
	testMenu->RegisterTest<test::TestTexture2d>("Texture 2d");
	testMenu->RegisterTest<test::video_rendering>("Video Rendering");
	testMenu->RegisterTest<test::test_3d_cube>("3d Cube");
	testMenu->RegisterTest<test::test_polygons>("Other Random Polygons");

	while (!glfwWindowShouldClose(Window::get()->get_window())) {
		/* resets to black at the menu */
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));

		processInput(Window::get()->get_window());

		Window::get()->get_renderer().Clear();
		
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

		glfwSwapBuffers(Window::get()->get_window());
		glfwPollEvents();
	}

	delete currentTest;
	if (currentTest != testMenu)
		delete testMenu;

	delete s_window;

	return 0;
}