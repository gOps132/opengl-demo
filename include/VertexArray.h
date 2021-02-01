#ifndef __VERTEXARRAY_H__
#define __VERTEXARRAY_H__

#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray {
  private:
	unsigned int m_RendererID;

  public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);
	void Bind() const;
	void Unbind() const;
};

#endif // __VERTEXARRAY_H__