#include "test_polygons.h"

#include "Core.h"

#include <vector>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include <imgui.h>

constexpr int m_height = 1080;
constexpr int m_width = 720;
constexpr int m_steps = 10;

namespace test {

test_polygons::test_polygons()
	: m_proj(
		  glm::ortho(0.0f, (float)m_height, 0.0f, float(m_width), -1.0f, 1.0f)),
	  m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
	  m_translation_a(500, 300, 0)
{
	// create circle [memory leaks may occur]
	// float *vertices;
	// create_circle(1.0f, m_steps, vertices);

	// test
	float vertices[] = {
		//  vertex coords   texture coords
		-100.0f, -100.0f, // top right    0
		100.0f,	 -100.0f, // bottom right 1
		-100.0f, 100.0f,  // top left     3

		100.0f,	 -100.0f, // bottom right 1
		100.0f,	 100.0f,  // bottom left  2
		-100.0f, 100.0f,  // top left     3
	};

	// for (int i = 0; i < m_steps; ++i) {
	// 	for (int y = 0; y < 8; y++) {
	// 		LOG_TEST_TRACE("DEBUG: vertices {}", vertices[y]);
	// 	}
	// }

	m_vao = std::make_unique<VertexArray>();
	m_vertexbfr = std::make_unique<VertexBuffer>(vertices, sizeof(vertices) *
															   sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);

	m_vao->AddBuffer(*m_vertexbfr, layout);
	m_shader = std::make_unique<Shader>("shaders/circle_shader.shader");
}

test_polygons::~test_polygons() {}

void test_polygons::OnUpdate(float deltaTime) {}

void test_polygons::OnRender()
{
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
	// GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
	Renderer renderer;

	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation_a);
	glm::mat4 mvp = m_proj * m_view * model;
	m_shader->Bind();
	m_shader->SetUniformMat4f("u_MVP", mvp);
	renderer.DrawVA(*m_vao, *m_shader, m_steps * 3);
}

void test_polygons::ImGuiRender()
{
	ImGui::SliderFloat3("m_translation_a", &m_translation_a.x, 0.0f,
						(float)m_height);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
				1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

void test_polygons::create_circle(const float radius,
								  const int p_steps, float *&vert)
{
	const float angle = (3.1415926 * 2.4f) / p_steps;
	int size = p_steps * (3 * 3);
	vert = new float[size];
	float xpos = 0;
	float ypos = 0;
	float px = xpos;
	float py = ypos - radius;
	int offset = 0;
	for (int i = 0; i < p_steps; ++i) {
		xpos = radius * sin(angle * i);
		ypos = -radius * cos(angle * i);
		// origin
		vert[0 + offset] = 0.0f;
		vert[1 + offset] = 0.0f;
		vert[2 + offset] = 0.0f;
		// prev v
		vert[3 + offset] = px;
		vert[4 + offset] = py;
		vert[5 + offset] = 0.0f;
		// new v
		vert[6 + offset] = xpos;
		vert[7 + offset] = ypos;
		vert[8 + offset] = 0.0f;
		offset += 9;
		px = xpos;
		py = ypos;
	}
}

} // namespace test