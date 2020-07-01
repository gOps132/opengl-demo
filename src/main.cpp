/*
 *
 *   Made by Epilan Gian Cedrick G.
 *   Most code by https://learnopengl.com, and the cherno https://youtube.com/thecherno
 * 
 * 	TODO: implement some kind of break point trap for every compiler
 * 	TODO: make some kind of manifest for xcode settings, compilers in order for the code to run right
 *	TODO: make a display class which handles the OpenGL context and the window and its destructor will call glfwterminate automatically.
 * 	TODO: make some kind of openGL context that handles the vertexbuffers, vertexarrays, indexbuffers and etc.
 * 
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

#include "Renderer.h"
#include "Shader.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "ErrorManager.h"
#include "Texture.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	int wHeight = 960;
	int wWidth = 540;

	GLFWwindow *window = glfwCreateWindow(wHeight, wWidth, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1); // synchronize with our vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, wHeight, wWidth);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	{
		float vertices[] = 
		{
		//vertex coords	   //texture coords
			100.0f,	100.0f, 	0.0f, 0.0f, 	// top right    0
			200.0f, 100.0f, 	1.0f, 0.0f,		// bottom right 1
			200.0f, 200.0f, 	1.0f, 1.0f, 	// bottom left  2
			100.0f, 200.0f, 	0.0f, 1.0f		// top left     3
		};
		unsigned int indices[] = 
		{
			// note that we start from 0!
			0, 1, 3, // first triangle
			1, 2, 3	 // second triangle
		};

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);

		IndexBuffer ib(indices, sizeof(indices));
		
		// TODO: abstract all these glm maths
		glm::mat4 proj = glm::ortho(0.0f, (float)wHeight, 0.0f, float(wWidth), -1.0f, 1.0f);
		/* position of the camera */
		glm::mat4 view = glm::translate(glm::mat4(1.0f) , glm::vec3(100, 0, 0));
		// position of the model (as far as i understand)
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

		// some other graphics api may not be in order (not communicative)
		glm::mat4 mvp = proj * view * model;

		VertexBuffer vb(vertices, sizeof(vertices) * sizeof(float));
		VertexArray va;
		va.AddBuffer(vb, layout);

		Shader shader("shaders/BasicShader.shader");
		shader.Bind(); 
		shader.SetUniformMat4f("u_MVP", mvp);

		Texture texture("textures/smile.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		/* unbinding */
		shader.Unbind();
		vb.Unbind();
		ib.Unbind();

		Renderer renderer;

		// uncomment this call to draw in wireframe polygons.
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		const char* glsl_version = "#version 150";

		/* ImGui Initialization */
  		IMGUI_CHECKVERSION();
    	ImGui::CreateContext();
    	ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);

		// Our state
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	
		// render loop
		// -----------
		//window render loop
		while (!glfwWindowShouldClose(window))
		{
			/* input */
			processInput(window);

			/* render here */	
			renderer.Clear();

			/* new imgui frame */
			// Start the Dear ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			
			/* Draw the vertices */
			renderer.Draw(va, ib, shader);

			// simple window
			{
				static float f = 0.0f;
				static int counter = 0;

				ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

				ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
				ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
				ImGui::Checkbox("Another Window", &show_another_window);

				ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
				ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

				if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
					counter++;
				ImGui::SameLine();
				ImGui::Text("counter = %d", counter);

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				ImGui::End();
        	}

			/* render imgui */
			ImGui::Render();
        	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	
			/* swaps buffers checks IO events */
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		/* ImGUI shutdown */
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();

		ImGui::DestroyContext();

		glfwTerminate();
	}

	return 0;
}