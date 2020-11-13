#ifndef __CORE_H__
#define __CORE_H__

#include "Log.h"

#include <debugbreak.h>

#define CORE_ASSERT(x, ...)                                                    \
    {                                                                          \
        if (!(x)) {                                                            \
            LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);                  \
            debug_break();                                                     \
        }                                                                      \
    }

#endif // __CORE_H__