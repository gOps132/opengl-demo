#include "Renderer.hpp"
#include <iostream>

void Renderer::Draw(const VertexArray &va, const IndexBuffer ib, const Shader &shader) const
{
    shader.Bind();

    va.Bind();
    ib.Bind();

    // the second parameter is the number of indices not the number of vertices
    glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
}