//
//  VertexArray.cpp
//  ALL_BUILD
//
//  Created by Gian Cedrick Epilan on 18/06/2020.
//

#include "VertexArray.h"
#include "Renderer.h"
#include "VertexBufferLayout.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElement();
    unsigned int offset = 0;
    for(int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
            i, element.count, element.type, element.normalized, 
            layout.GetStride(), (const void*)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() const
{
    // GLCall(glBindVertexArray(m_RendererID));
    glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const
{
    // GLCall(glBindVertexArray(0));
    glBindVertexArray(0);
}
