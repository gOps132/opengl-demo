#include "test_3d_cube.h"

#include "VertexBufferLayout.h"
#include "Renderer.h"

#include <imgui.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>
namespace test {
constexpr int m_height = 1080;
constexpr int m_width = 720;

test_3d_cube::test_3d_cube()
	: m_Proj(glm::perspective(glm::radians(45.0f), (float)(m_height / m_width),
							  0.1f, 10.0f)),
	  cc_a(0.5f, 0.0f, 3.0f), cc_b(0.0f, 0.0f, 0.0f), cc_c(0.0f, 0.0f, 1.0f),
	  m_TranslationA(0, 0, 0)
{
	// TODO: Set a test API for these callback functions
	// glfwSetKeyCallback(window, [this](GLFWwindow *p_window, int p_button,
	// 								  int p_action, int p_mode) {
	// 	GLfloat cameraSpeed = 0.05f;
	// 	if (p_button == GLFW_KEY_W)
	// 		cc_a += cameraSpeed * cc_b;
	// 	if (p_button == GLFW_KEY_S)
	// 		cc_a -= cameraSpeed * cameraFront;
	// 	if (p_button == GLFW_KEY_A)
	// 		cc_a -=
	// 			glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	// 	if (p_button == GLFW_KEY_D)
	// 		cc_a +=
	// 			glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	// });

	float vertices[] = {
		// front
		-1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0,
		// back
		-1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0};

	unsigned int indices[] = {// front
							  0, 1, 2, 2, 3, 0,
							  // right
							  1, 5, 6, 6, 2, 1,
							  // back
							  7, 6, 5, 5, 4, 7,
							  // left
							  4, 0, 3, 3, 7, 4,
							  // bottom
							  4, 5, 1, 1, 0, 4,
							  // top
							  3, 2, 6, 6, 7, 3};

	m_VAO = std::make_unique<VertexArray>();
	m_VertexBuffer = std::make_unique<VertexBuffer>(
		vertices, sizeof(vertices) * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(3);

	m_VAO->AddBuffer(*m_VertexBuffer, layout);

	m_IndexBuffer = std::make_unique<IndexBuffer>(indices, sizeof(indices));
	m_Shader = std::make_unique<Shader>("shaders/test_3d_cube.shader");
	m_Texture = std::make_unique<Texture>("textures/poop.png");
}

test_3d_cube::~test_3d_cube() {}

void test_3d_cube::OnUpdate(float deltaTime) {}

void test_3d_cube::OnRender()
{
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
	GLCall(glEnable(GL_DEPTH_TEST));

	// GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));

	Renderer renderer;
	// m_Texture->Bind(0);

	// glm::mat4 model = glm::rotate(glm::mat4(1.0f), 45.0f, m_TranslationA);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);

	m_View = glm::lookAt(cc_a, cc_b, cc_c);

	glm::mat4 mvp = m_Proj * m_View * model;
	m_Shader->Bind();
	m_Shader->SetUniformMat4f("u_MVP", mvp);

	renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
}

void test_3d_cube::ImGuiRender()
{
	ImGui::SliderFloat3("m_TranslationA", &m_TranslationA.x, 0.0f,
						(float)m_height);
	ImGui::SliderFloat3("camera coordinate a", &cc_a.x, 0.0f, (float)m_height);
	ImGui::SliderFloat3("camera coordinate b", &cc_b.x, 0.0f, (float)m_height);
	ImGui::SliderFloat3("camera coordinate c", &cc_c.x, 0.0f, (float)m_height);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
				1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

} // namespace test