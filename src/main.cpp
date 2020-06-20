/*
	*   Made by Epilan Gian Cedrick G.
	*   Most code by https://learnopengl.com, and the cherno https://youtube.com/thecherno
	*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer.hpp"
#include "Shader.hpp"

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "VertexArray.hpp"
#include "VertexBufferLayout.hpp"

#include <iostream>

/*
	*	TODO: implement some kind of break point trap for every compiler
	* 	TODO: make some kind of manifest for xcode settings, compilers in order for the code to run right
	*	TODO: make a display class which handles the OpenGL context and the window and its destructor will call glfwterminate automatically.
*/

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

	GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	{
		float vertices[] = {
			0.5f,	0.5f,	0.0f,	// top right    0
			0.5f,  -0.5f,	0.0f,	// bottom right 1
		   -0.5f,  -0.5f,	0.0f, // bottom left  2
		   -0.5f,	0.5f,	0.0f	// top left     3
		};
		unsigned int indices[] = {
			// note that we start from 0!
			0, 1, 3, // first triangle
			1, 2, 3	 // second triangle
		};

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		VertexArray va;
		VertexBuffer vb(vertices, sizeof(vertices));
		VertexBufferLayout layout;

		// va.AddBuffer(vb, &layout);
		layout.Push<float>(3);
		va.AddBuffer(vb, layout);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);

		IndexBuffer ib(indices, sizeof(indices));

		// uncomment this call to draw in wireframe polygons.
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		ShaderProgramSource source = ParseShader("shaders/BasicShader.shader");
		unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
		glUseProgram(shader);

		//     set uniforms
		int location = glGetUniformLocation(shader, "u_Color");
		ASSERT(location != -1);
		glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f);

		float r = 0.0f;
		float increment = 0.05f;
		// render loop
		// -----------
		//window render loop
		while (!glfwWindowShouldClose(window))
		{
			//input
			processInput(window);

			//rendering commands here
			glUniform4f(location, r, 0.3f, 0.8f, 1.0f);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			va.Bind();
			ib.Bind();

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // the second parameter is the number of indices not the number of vertices
			if (r > 1.0f)
				increment = -0.05f;
			else if (r < 0.0f)
				increment = 0.05f;
			r += increment;

			// glBindVertexArray(0); // no need to unbind it every time

			// check and call events and swap the buffers
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

	return 0;
}
