#shader vertex
#version 330 core

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec2 texCoord;

out vec4 v_color;
out vec2 v_TexCoord;
uniform mat4 u_MVP;

void main()
{
	gl_Position =  u_MVP * aPos;
	v_TexCoord = texCoord;
	v_color = aPos;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_color;
in vec2 v_TexCoord;

uniform sampler2D u_Texture;
// uniform samplerCube u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture, v_TexCoord);
	color = texColor;
	// color = v_color;
}