//
//  VertexArray.hpp
//  ALL_BUILD
//
//  Created by Gian Cedrick Epilan on 18/06/2020.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

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

#endif /* VertexArray_hpp */
