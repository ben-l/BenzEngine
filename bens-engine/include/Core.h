#pragma once

#ifdef __linux__ 
    //linux code goes here
    #define BENS_ENGINE_API __attribute__((visibility("default")))
#else
#error Bens Engine only supports Linux!
#endif

#ifdef BE_DEBUG
    #define BE_ENABLE_ASSERTS
#endif

#ifdef BE_ENABLE_ASSERTS
    #define BE_ASSERT(x, ...) { if(!(x)) { \
            BE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak(); } }
    #define BE_CORE_ASSERT(x, ...) { if(!(x)) { \
            BE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak(); } }
#else
    #define BE_ASSERT(x, ...)
    #define BE_CORE_ASSERT(x, ...)
#endif


// binary - shift 1 by x places to the left
// so 1 added by (x) 0s e.g. BIT(4) == 1000
// converted to decimal is 16
#define BIT(x) (1 << x)

#define BE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

