#ifndef __TEST_3D_CUBE_H__
#define __TEST_3D_CUBE_H__

#include "Test.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"

#include <glm/glm.hpp>

#include <chrono>

namespace test {

class test_3d_cube : public Test {
  public:
	test_3d_cube();
	~test_3d_cube();

	virtual void OnUpdate(float deltaTime) override;
	virtual void OnRender() override;
	virtual void ImGuiRender() override;

  private:
	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<IndexBuffer> m_IndexBuffer;
	std::unique_ptr<Shader> m_Shader;
	std::unique_ptr<Texture> m_Texture;
	std::unique_ptr<VertexBuffer> m_VertexBuffer;

	glm::mat4 m_Proj, m_View;
	glm::vec3 m_TranslationA, cc_a, cc_b, cc_c;

	// std::__1::chrono::steady_clock::time_point t_start;
};

} // namespace test

#endif // __TEST_3D_CUBE_H__