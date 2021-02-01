/*
 *  simple parser that passes shader file and convert them into strings
 */

#include "Shader.h"
#include "ErrorManager.h"
#include <glm/glm.hpp>

// TODO: Optimize passShader function into faster c api. c++ tends to be a lot
// slower than the c api but this is just openGL for now.

Shader::Shader(const std::string &filepath)
	: m_FilePath(filepath), m_RendererID(0)
{
	ShaderProgramSource source = ParseShader(filepath);
	m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader() { GLCall(glDeleteProgram(m_RendererID)); }

void Shader::Bind() const { GLCall(glUseProgram(m_RendererID)); }

void Shader::Unbind() const { GLCall(glUseProgram(0)); }

// FIXME: GL_INVALID_OPERATION 0x0502
void Shader::SetUniform1i(const std::string &name, int value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUniform1f(const std::string &name, float value)
{
	GLCall(glUniform1f(GetUniformLocation(name), value));
}

void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2,
						  float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniformMat4f(const std::string &name, const glm::mat4 &matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE,
							  &matrix[0][0]));
}

int Shader::GetUniformLocation(const std::string &name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

#ifndef __glad_h
	GLCall(int location =
			   ::glad_glGetUniformLocation(m_RendererID, name.c_str()));
#endif

#ifdef __glew_h
	GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
#endif

	if (location == -1)
		LOG_CORE_WARN("Warning: Uniform {0} does not exist", name);
	else
		m_UniformLocationCache[name] = location;

	return location;
}

ShaderProgramSource Shader::ParseShader(const std::string &filepath)
{
	enum class ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1 };

	std::ifstream stream(filepath); // opens the file
	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (std::getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;

			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::CompileShader(unsigned int type, const std::string &source)
{
	unsigned int id = glCreateShader(type);
	const char *src = source.c_str();
	GLCall(glShaderSource(id, 1, &src, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) {
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		// alloca not recommended
		char *message = (char *)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		LOG_CORE_ERROR("Fail to compile {0} shader!",
					   (type == GL_VERTEX_SHADER ? "vertex" : "fragment"));
		LOG_CORE_ERROR("{0}", message);
		GLCall(glDeleteShader(id));

		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string &vertexShader,
								  const std::string &fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}