#ifndef __VERTEXBUFFER_H__
#define __VERTEXBUFFER_H__

class VertexBuffer {
  private:
	unsigned int m_RendererID;

  public:
	VertexBuffer(const void *data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

#endif // __VERTEXBUFFER_H__