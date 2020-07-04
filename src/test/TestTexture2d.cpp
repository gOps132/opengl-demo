//
// Created by Gian Cedrick Epilan on 02/07/2020.
//

#include "TestTexture2d.h"
#include "ErrorManager.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>
#include <imgui/imgui.h>

namespace test {

    int wHeight = 1080;
    int wWidth = 720;

    TestTexture2d::TestTexture2d()
    {
        float vertices[] = {
                    //vertex coords	   //texture coords
                    - 50.0f, -50.0f,    0.0f, 0.0f, 	// top right    0
                      50.0f, -50.0f,    1.0f, 0.0f,		// bottom right 1
                      50.0f,  50.0f,    1.0f, 1.0f, 	// bottom left  2
                     -50.0f,  50.0f, 	0.0f, 1.0f		// top left     3
                };
        unsigned int indices[] = {
                        // note that we start from 0!
                        0, 1, 3, // first triangle
                        1, 2, 3	 // second triangle
                };

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        VertexBuffer vb(vertices, sizeof(vertices) * sizeof(float));
        VertexArray va;
        VertexBufferLayout layout;

        va.AddBuffer(vb, layout);

        layout.Push<float>(2);
        layout.Push<float>(2);

        glm::mat4 proj = glm::ortho(0.0f, (float)wHeight, 0.0f, float(wWidth), -1.0f, 1.0f);
        /* position of the camera */
        glm::mat4 view = glm::translate(glm::mat4(1.0f) , glm::vec3(0, 0, 0));

        Shader shader("shaders/BasicShader.shader");
        shader.Bind();

        Texture texture("textures/smile.png");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);

        IndexBuffer ib(indices, sizeof(indices));

        /* unbinding */
        shader.Unbind();
        vb.Unbind();
        ib.Unbind();
    }

    TestTexture2d::~TestTexture2d()
    {
    }

    void TestTexture2d::OnUpdate(float deltaTime)
    {
    }

    void TestTexture2d::OnRender()
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void TestTexture2d::ImGuiRender()
    {
    }

}
