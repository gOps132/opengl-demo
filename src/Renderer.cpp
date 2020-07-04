#include "Renderer.h"

void Renderer::Draw(const VertexArray &va, const IndexBuffer& ib, const Shader &shader) const
{
    shader.Bind();

    va.Bind();
    ib.Bind();

    // the second parameter is the number of indices not the number of vertices
    glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::SetClearColor() const
{
}

void Renderer::Clear() const
{
    // set background color
    // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


