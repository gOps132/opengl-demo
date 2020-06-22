#ifndef IndexBuffer_hpp
#define IndexBuffer_hpp
class IndexBuffer 
{
private:
    unsigned int m_RendererID; // renderer id, is just the actual internal render id
    unsigned int m_Count; // how many indeces do we have
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int getCount() const { return m_Count; }
};

#endif