#ifndef __ERRORMANAGER_H__
#define __ERRORMANAGER_H__

#include "signal.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <debugbreak.h>

#ifdef DEBUG
#define GLCall(x)                                                              \
    GLClearError();                                                            \
    x;                                                                         \
    if (!(x)) {                                                                \
        std::cout << "GLLogCall Assertion failed" << '\n';                     \
        debug_break();                                                         \
    }
#else
#define GLCall(x) x
#endif

void GLClearError();

int GLLogCall(const char *function, const char *file, int line);

#endif // __ERRORMANAGER_H__