#ifndef __ERRORMANAGER_H__
#define __ERRORMANAGER_H__

#include "Core.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#ifndef DEBUG
#define GLCall(x)                                                              \
    GLClearError();                                                            \
    x;                                                                         \
    CORE_ASSERT(GLLogCall(#x, __FILE__, __LINE__), "GLCALL FAILED!");
#else
#define GLCall(x) x
#endif

void GLClearError();

int GLLogCall(const char *function, const char *file, int line);

#endif // __ERRORMANAGER_H__