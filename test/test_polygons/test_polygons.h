#ifndef __TEST_POLYGONS_H__
#define __TEST_POLYGONS_H__

#include "Test.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Renderer.h"

#include <utility>
#include <glm/glm.hpp>

namespace test {
class test_polygons : public Test {
  public:
	test_polygons();
	virtual ~test_polygons();

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnRender() override;
	virtual void ImGuiRender() override;

	/* indices not needed */
	float* create_circle(const float radius, const unsigned int p_steps);
  private:
	std::unique_ptr<VertexArray> m_vao;
	std::unique_ptr<Shader> m_shader;
	std::unique_ptr<VertexBuffer> m_vertexbfr;

	glm::mat4 m_proj, m_view;
	glm::vec3 m_translation_a;// cc_a, cc_b, cc_c;
	float m_clear_color[4];
};

} // namespace test

#endif // __TEST_POLYGONS_H__