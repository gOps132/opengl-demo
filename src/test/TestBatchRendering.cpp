//
// Created by Gian Cedrick Epilan on 05/07/2020.
//

#include "TestBatchRendering.h"

#include "TestBatchRendering.h"
#include "ErrorManager.h"

#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

#include "Shader.h"
#include "Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <imgui/imgui.h>

#include <memory>

namespace test {

    int w_Height = 1080;
    int w_Width = 720;

    TestBatchRendering::TestBatchRendering()
            :
            m_Proj(glm::ortho(0.0f, (float)w_Height, 0.0f, float(w_Width), -1.0f, 1.0f)),
            m_View(glm::translate(glm::mat4(1.0f) , glm::vec3(0, 0, 0))),
            m_TranslationA(200, 200, 0)
    {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        float vertices[] = {
                //vertex coords	   //texture coords
                -50.0f, -50.0f,     0.0f, 0.0f, 	// top right    0
                 50.0f, -50.0f,     1.0f, 0.0f,		// bottom right 1
                 50.0f,  50.0f,     1.0f, 1.0f, 	// bottom left  2
                -50.0f,  50.0f,     0.0f, 1.0f		// top left     3
        };
        unsigned int indices[] = {
                // note that we start from 0!
                0, 1, 3, // first triangle
                1, 2, 3	 // second triangle
        };

        m_VAO = std::make_unique<VertexArray>();

        m_VertexBuffer = std::make_unique<VertexBuffer>(vertices, sizeof(vertices) * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);

        m_VAO->AddBuffer(*m_VertexBuffer, layout);
        m_IndexBuffer = std::make_unique<IndexBuffer>(indices, sizeof(indices));

        m_Shader = std::make_unique<Shader>("shaders/BasicShader.shader");

        m_Texture = std::make_unique<Texture>("textures/smile.png");
        m_Shader->SetUniform1i("u_Texture", 0);
    }

    TestBatchRendering::~TestBatchRendering()
    {
    }

    void TestBatchRendering::OnUpdate(float deltaTime)
    {
    }

    void TestBatchRendering::OnRender()
    {

        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        Renderer renderer;

        m_Texture->Bind();

        {
            /* Recalculating the model matrix every frame */
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);
            glm::mat4 mvp = m_Proj * m_View * model;
            m_Shader->Bind(); /* Bind to set the uniform */
            m_Shader->SetUniformMat4f("u_MVP", mvp);
            renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
        }
    }

    void TestBatchRendering::ImGuiRender()
    {
        ImGui::SliderFloat3("m_TranslationA", &m_TranslationA.x, 0.0f, (float)w_Height);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }

}
