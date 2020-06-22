#ifndef __ERRORMANAGER_H__
#define __ERRORMANAGER_H__

/*
 * Add -DDEBUG flag to clang llvm compiler or other compilers
 * FIXME: Deal with bug that breakpoints even if assertion is okay
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>

#ifdef DEBUG
#ifdef __APPLE__
#define ASSERT(x) \
        if (!(x)) \
        __builtin_debugtrap() // works with xcode built in compiler
#endif
#ifdef __linux__
#define ASSERT(x) \
        if (!(x)) \
        raise(SIGTRAP) // works with clang (more research)
#endif
#ifdef _WIN32
#define ASSERT(x) \
        if (!(x)) \
                __debugbreak(); // works with VS MSVC compiler intrinsic
#endif
#define GLCall(x)       \
        GLClearError(); \
        x;              \
        ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define ASSERT(x) \
        if (!(x)) \
        raise(SIGABRT)
#define GLCall(x) x
#endif

class ErrorManager
{
public:
    void GLClearError();

    bool GLLogCall(const char *function, const char *file, int line);
};


#endif // __ERRORMANAGER_H__