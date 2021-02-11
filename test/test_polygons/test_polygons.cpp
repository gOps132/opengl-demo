#include "test_polygons.h"

#include "Core.h"

#include <vector>
#include <math.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <imgui.h>

constexpr int m_width = 1080;
constexpr int m_height = 720;
constexpr unsigned int m_steps = 100;

namespace test {

test_polygons::test_polygons()
	: m_proj(
		  glm::ortho(0.0f, (float)m_height, 0.0f, float(m_width), -1.0f, 1.0f)),
	  m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
{
	// create circle [memory leaks may occur]
	float *vertices = create_circle(1.0f, m_steps);

	for (int i = 0; i < 18; i++) {
		LOG_CORE_INFO("DEBUG: SIZEOF RET IS: {}", vertices[i]);
	}

	m_vao = std::make_unique<VertexArray>();
	m_vertexbfr = std::make_unique<VertexBuffer>(vertices, sizeof(vertices) *
															   sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(3);

	m_vao->AddBuffer(*m_vertexbfr, layout);
	m_shader = std::make_unique<Shader>("shaders/circle_shader.shader");
}

test_polygons::~test_polygons() {}

void test_polygons::OnUpdate(float deltaTime) {}

void test_polygons::OnRender()
{
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
	// GLCall(glEnable(GL_DEPTH_TEST));
	// GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
	Renderer renderer;

	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation_a);
	// m_view = glm::lookAt(cc_a, cc_b, cc_c);
	glm::mat4 mvp = m_proj * m_view * model;
	m_shader->Bind();
	m_shader->SetUniformMat4f("u_MVP", mvp);
	renderer.DrawVA(*m_vao, *m_shader, m_steps);
}

void test_polygons::ImGuiRender()
{
	ImGui::SliderFloat3("m_translation_a", &m_translation_a.x, 0.0f,
						(float)m_height);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
				1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

float *test_polygons::create_circle(const float radius,
									const unsigned int p_steps)
{
	const float angle = 3.1415926 * 2.4f / p_steps;

	int size = p_steps * 3;
	float ret[size];
	float xpos = 0;
	float ypos = 0;
	float px = xpos;
	float py = ypos - radius;
	//FIXME: overflows here
	for (int s = 0; s < p_steps; ++s) {
		xpos = radius * sin(angle * s);
		ypos = -radius * cos(angle * s);
		int iter = -1;
		ret[iter + 1] = 0;
		ret[iter + 2] = xpos;
		ret[iter + 3] = ypos;
		iter++;
	}
	return ret;
}

} // namespace test