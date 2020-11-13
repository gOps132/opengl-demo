#ifndef __INDEXBUFFER_H__
#define __INDEXBUFFER_H__

class IndexBuffer 
{
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int getCount() const { return m_Count; }
};

#endif // __INDEXBUFFER_H__