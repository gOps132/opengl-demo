#ifndef __VERTEXARRAY_H__
#define __VERTEXARRAY_H__

//
//  VertexArray.hpp
//  ALL_BUILD
//
//  Created by Gian Cedrick Epilan on 18/06/2020.
//

#include "VertexBuffer.h"

// #include "VertexBufferLayout.hpp"

class VertexBufferLayout;

class VertexArray 
{
private:
    unsigned int m_RendererID;
    
public:
    VertexArray();
    ~VertexArray();

    /* create vertex buffer */
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
     
    /* Bind the vertex array */
    void Bind() const;

    /* unbind the vertex array */
    void Unbind() const;
};

#endif // __VERTEXARRAY_H__