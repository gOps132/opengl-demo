/*
 *   Made by Epilan Gian Cedrick G.
 *   Most code by https://learnopengl.com, and the cherno https://youtube.com/thecherno
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer.h"
#include "Shader.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "ErrorManager.h"
#include "Texture.h"

#include <iostream>

/*
	*	TODO: implement some kind of break point trap for every compiler
	* 	TODO: make some kind of manifest for xcode settings, compilers in order for the code to run right
	*	TODO: make a display class which handles the OpenGL context and the window and its destructor will call glfwterminate automatically.
	* 	TODO: make some kind of openGL context that handles the vertexbuffers, vertexarrays, indexbuffers and etc.
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
		float vertices[] = {
		//vertex coords	   //texture coords
			100.0f,	100.0f, 	0.0f, 0.0f, 	// top right    0
			200.0f, 100.0f, 	1.0f, 0.0f,		// bottom right 1
			200.0f, 200.0f, 	1.0f, 1.0f, 	// bottom left  2
			100.0f, 200.0f, 	0.0f, 1.0f		// top left     3
		};
		unsigned int indices[] = {
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
		
		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);

		VertexBuffer vb(vertices, sizeof(vertices) * sizeof(float));
		VertexArray va;
		va.AddBuffer(vb, layout);

		Shader shader("shaders/BasicShader.shader");
		shader.Bind(); 
		// not using "u_Color" right now
		// shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);
		shader.SetUniformMat4f("u_MVP", proj);

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
		
		float r = 0.0f;
		float increment = 0.05f;

		// render loop
		// -----------
		//window render loop
		while (!glfwWindowShouldClose(window))
		{
			/* input */
			processInput(window);

			/* render here */	
			renderer.Clear();
            
			renderer.Draw(va, ib, shader);
            
			// not using "u_Color" will cause errors
			// shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
            
			if (r > 1.0f)
				increment = -0.05f;
			else if (r < 0.0f)
				increment = 0.05f;
			r += increment;

			/* swaps buffers checks IO events */
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
	}

	return 0;
}
