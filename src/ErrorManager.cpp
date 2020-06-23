#include "ErrorManager.hpp"
#include <glad/glad.h>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char *function, const char *file, int line)
{
    if (GLenum error = glGetError())
    {
        //        display function with hexcode
        std::cout << "[OpenGL Error] " << std::endl
                  << function << std::endl
                  << file << ":" << line << std::endl
                  << std::endl;

        //        TODO: make this faster with the c api
        //        display the name of the errors
        std::stringstream ss;
        ss << std::hex << error; // decimal_value
        std::string res(ss.str());
        std::string new_string = std::string(4 - res.length(), '0') + res;
        std::ifstream stream("lib/glad/include/glad/glad.h");
        std::string line;
        while (getline(stream, line))
        {
            if (line.find(new_string) != std::string::npos)
                std::cout << line << std::endl;
        }

        return false;
    }

    return false;
}