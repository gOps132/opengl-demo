#ifndef __ERRORMANAGER_H__
#define __ERRORMANAGER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

/*
 * FIXME: Deal with bug that breakpoints even if assertion is okay
 */

#ifdef DEBUG
#define GLCall(x)       \
        GLClearError(); \
        x;              \
        assert(GLLogCall(#x, __FILE__, __LINE__))
#else
    #define GLCall(x) x
#endif

void GLClearError();

int GLLogCall(const char *function, const char *file, int line);

#endif // __ERRORMANAGER_H__
