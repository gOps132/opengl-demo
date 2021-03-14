#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
class Renderer {
  public:
	void Clear() const;
	void SetClearColor() const;
	void Draw(const VertexArray &va, const IndexBuffer &ib,
			  const Shader &shader) const;
	/* Render without index buffer */
	void DrawVA(const VertexArray &va, const Shader &shader,
				unsigned int va_count) const;
};

#endif // __RENDERER_H__