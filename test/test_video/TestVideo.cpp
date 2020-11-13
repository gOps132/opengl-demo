//
// Created by Gian Cedrick Epilan on 02/07/2020.
//

/*
 * TODO: fix the problem whereas, you have to bind the shader in order to set
 * the uniform
 */

#include "TestVideo.h"
#include "ErrorManager.h"

#include "IndexBuffer.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include "Renderer.h"
#include "Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>

#include <memory>

namespace test {

constexpr int wHeight = 1080;
constexpr int wWidth = 720;

TestVideo::TestVideo()
    : m_Proj(
          glm::ortho(0.0f, (float)wHeight, 0.0f, float(wWidth), -1.0f, 1.0f)),
      m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
      m_TranslationA(200, 200, 0), m_TranslationB(400, 200, 0)
{
    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    float vertices[] = {
        // vertex coords    //texture coords
        -50.0f, -50.0f,     0.0f, 0.0f, // top right    0
         50.0f, -50.0f,     1.0f, 0.0f, // bottom right 1
         50.0f,  50.0f,     1.0f, 1.0f, // bottom left  2
        -50.0f,  50.0f,     0.0f, 1.0f  // top left     3
    };
    
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    m_VAO = std::make_unique<VertexArray>();
    m_VertexBuffer = std::make_unique<VertexBuffer>(
        vertices, sizeof(vertices) * sizeof(float));
    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);

    m_VAO->AddBuffer(*m_VertexBuffer, layout);
    m_IndexBuffer = std::make_unique<IndexBuffer>(indices, sizeof(indices));

    m_Shader = std::make_unique<Shader>("shaders/BasicShader.shader");

    m_Texture = std::make_unique<Texture>("textures/smile.png");
    m_Shader->SetUniform1i("u_Texture", 0);
}

TestVideo::~TestVideo() {}

void TestVideo::OnUpdate(float deltaTime) {}

void TestVideo::OnRender()
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
    {
        /* Recalculating the model matrix every frame */
        glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationB);
        glm::mat4 mvp = m_Proj * m_View * model;
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_MVP", mvp);
        renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
    }
}
} // namespace test
