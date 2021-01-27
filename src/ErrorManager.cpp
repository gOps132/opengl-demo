#include "ErrorManager.h"

#include "Log.h"

#include <glad/glad.h>

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR)
        ;
}

int GLLogCall(const char *function, const char *file, int line)
{
    if (GLenum error = glGetError()) {
        LOG_CORE_ERROR("OPENGL ERROR: ");
        LOG_CORE_ERROR("     FUNCTION: {0}", function);
        LOG_CORE_ERROR("     FILE: {0}", file);
        LOG_CORE_ERROR("     LINE: {0}", line);

        // TODO: make this faster with the c api
        std::stringstream ss;
        ss << std::hex << error;
        std::string res(ss.str());
        std::string new_string = std::string(4 - res.length(), '0') + res;
        std::ifstream stream("lib/glad/include/glad/glad.h");
        std::string line;
        while (getline(stream, line)) {
            if (line.find(new_string) != std::string::npos)
                LOG_CORE_INFO("{0}", line);
        }

        return -1;
    }

    return 1;
}
