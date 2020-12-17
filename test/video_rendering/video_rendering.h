#ifndef __VIDEO_RENDERING_H__
#define __VIDEO_RENDERING_H__

#include "Test.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace test
{
    class video_rendering : public Test
    {
    public:
        video_rendering();
        ~video_rendering();

        virtual void OnUpdate(float deltaTime) override;
        virtual void OnRender() override;
        virtual void ImGuiRender() override;

    private:
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<Texture> m_Texture;

        glm::mat4 m_Proj, m_View;

        glm::vec3 m_TranslationA, m_TranslationB;
    };
    
} // namespace test

#endif // __VIDEO_RENDERING_H__