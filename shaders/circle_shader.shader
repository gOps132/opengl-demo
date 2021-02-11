#shader vertex
#version 330 core

layout (location = 0) in vec4 aPos;

out vec4 v_color;
uniform mat4 u_MVP;

void main()
{
	gl_Position =  u_MVP * aPos;
	v_color = aPos;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_color;

void main()
{
	color = v_color;
}