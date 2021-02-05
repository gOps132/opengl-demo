#include "Renderer.h"
#include "ErrorManager.h"

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib,
					const Shader &shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, 0));
}

void Renderer::DrawVA(const VertexArray &va, const Shader &shader,
					  unsigned int va_count = 0) const
{
	shader.Bind();
	va.Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, va_count));
}

void Renderer::SetClearColor() const {}

void Renderer::Clear() const { GLCall(glClear(GL_COLOR_BUFFER_BIT)); }