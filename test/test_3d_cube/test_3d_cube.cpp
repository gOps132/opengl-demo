#include "test_3d_cube.h"

#include "VertexBufferLayout.h"
#include "Renderer.h"

#include <imgui.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace test {
constexpr int m_height = 1080;
constexpr int m_width = 720;

test_3d_cube::test_3d_cube()
	: m_Proj(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.0f, 10.0f)),
	  m_View(glm::lookAt(glm::vec3(1.2f, 1.2f, 1.2f),
						 glm::vec3(0.0f, 0.0f, 0.0f),
						 glm::vec3(0.0f, 0.0f, 1.0f))),
	  m_TranslationA(200, 200, 0)
{
	// float vertices[] = {
	// 	1.0f,  1.0f,  1.f,	1.0f, 0.0f, 0.0f, // 0
	// 	-1.0f, 1.0f,  1.f,	0.0f, 1.0f, 0.0f, // 1
	// 	-1.0f, 1.0f,  -1.f, 0.0f, 0.0f, 1.0f, // 2
	// 	1.0f,  1.0f,  -1.f, 1.0f, 1.0f, 1.0f, // 3
	// 	1.0f,  -1.0f, 1.f,	1.0f, 1.0f, 0.0f, // 4
	// 	-1.0f, -1.0f, 1.f,	1.0f, 1.0f, 1.0f, // 5
	// 	-1.0f, -1.0f, -1.f, 0.0f, 1.0f, 1.0f, // 6
	// 	1.0f,  -1.0f, -1.f, 1.0f, 0.0f, 1.0f  // 7
	// };

	// unsigned int indices[] = {
	// 	0, 1, 3, // top 1
	// 	3, 1, 2, // top 2
	// 	2, 6, 7, // front 1
	// 	7, 3, 2, // front 2
	// 	7, 6, 5, // bottom 1
	// 	5, 4, 7, // bottom 2
	// 	5, 1, 4, // back 1
	// 	4, 1, 0, // back 2
	// 	4, 3, 7, // right 1
	// 	3, 4, 0, // right 2
	// 	5, 6, 2, // left 1
	// 	5, 1, 2	 // left 2
	// };

	float vertices[] = {
		//  vertex coords   texture coords
		-50.0f, -50.0f, 0.0f, 0.0f, // top right    0
		50.0f,	 -50.0f, 1.0f, 0.0f, // bottom right 1
		50.0f,	 50.0f,  1.0f, 1.0f, // bottom left  2
		-50.0f, 50.0f,  0.0f, 1.0f  // top left     3
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3	 // second triangle
	};

	m_VAO = std::make_unique<VertexArray>();
	m_VertexBuffer = std::make_unique<VertexBuffer>(
		vertices, sizeof(vertices) * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);

	m_VAO->AddBuffer(*m_VertexBuffer, layout);

	m_IndexBuffer = std::make_unique<IndexBuffer>(indices, sizeof(indices));
	m_Shader = std::make_unique<Shader>("shaders/test_3d_cube.shader");
	m_Texture = std::make_unique<Texture>("textures/smile.png");
}

test_3d_cube::~test_3d_cube() {}

void test_3d_cube::OnUpdate(float deltaTime) {}

void test_3d_cube::OnRender()
{
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	Renderer renderer;

	m_Texture->Bind(0);

	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);
	glm::mat4 mvp = m_Proj * m_View * model;
	m_Shader->Bind();
	m_Shader->SetUniformMat4f("u_MVP", mvp);
	renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
}

void test_3d_cube::ImGuiRender()
{
	ImGui::SliderFloat3("m_TranslationA", &m_TranslationA.x, 0.0f,
						(float)m_height);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
				1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

} // namespace test