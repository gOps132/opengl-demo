#include "video_rendering.h"

#include "ErrorManager.h"

#include <glad/glad.h>

namespace test {
video_rendering::video_rendering() {}

video_rendering::~video_rendering() {}

void video_rendering::OnUpdate(float deltaTime) {}

void video_rendering::OnRender()
{
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void video_rendering::ImGuiRender() {}
} // namespace test