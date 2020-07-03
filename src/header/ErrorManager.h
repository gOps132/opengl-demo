#ifndef __ERRORMANAGER_H__
#define __ERRORMANAGER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
 * FIXME: Deal with bug that breakpoints even if assertion is okay
 */

#ifdef DEBUG
//#define ASSERT(x) if(!(x)) std::cin.ignore();
#define ASSERT(x) \
        if(!(x)) \
        std::cout << "error of some kind" << std::endl; \
        std::cin.ignore();

#define GLCall(x)       \
        GLClearError(); \
        x;              \
        ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define GLCall(x) x
#define ASSERT(x) x
#endif

void GLClearError();

bool GLLogCall(const char *function, const char *file, int line);


#endif // __ERRORMANAGER_H__
