#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <glad/glad.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"


class Renderer
{
public:
        void Clear() const;
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif // __RENDERER_H__