#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

// TODO: Optimize passShader function into faster c api. c++ tends to be a lot slower than the c api but this is just openGL for now.

class Shader
{ 
private:
    std::string m_FilePath;
    unsigned int m_RendererID;
    // caching for unforms
    std::unordered_map<std::string, int> m_UniformLocationChache;

public:
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    // set uniforms
    void SetUniform1i(const std::string& name, int value);
    void SetUniform1f(const std::string& name, float value);
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

    void glGetUniformLocation(const std::string& name);
private:
    // simple parser that passes shader file and convert them into strings 
    ShaderProgramSource ParseShader(const std::string &filepath);

    // use to retrieve opengl uniform location
    int GetUniformLocation(const std::string& name);

    // creates, attach, and deletes input vertex and  fragment shaders
    unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

    // setups, compile shader and catch GL errors from input shaders 
    unsigned int CompileShader(unsigned int type, const std::string &source);

};


#endif // __SHADER_H__