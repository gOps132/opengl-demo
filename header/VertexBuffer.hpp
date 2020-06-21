#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

class VertexBuffer 
{
private:
    unsigned int m_RendererID; // renderer id, is jus the actual internal rendere id 
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};

#endif