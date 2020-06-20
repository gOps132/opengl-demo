#ifndef Shader_hpp
#define Shader_hpp

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

// TODO: Optimize passShader function into faster c api. c++ tends to be a lot slower than the c api but this is just openGL for now.

/* simple parser that passes shader file and convert them into strings */
ShaderProgramSource ParseShader(const std::string &filepath);

/* setups, compile shader and catch GL errors from input shaders */
unsigned int CompileShader(unsigned int type, const std::string &source);

/* creates, attach, and deletes input vertex and  fragment shaders */
unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

#endif
