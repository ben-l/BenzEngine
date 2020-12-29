#pragma once

#ifdef __linux__ 
    //linux code goes here
    #define BENS_ENGINE_API __attribute__((visibility("default")))
    // windows code goes here
#else
#error Bens Engine only supports Linux!
#endif

// binary - shift 1 by x places to the left
// so 1 added by (x) 0s e.g. BIT(4) == 1000
// converted to decimal is 16
#define BIT(x) (1 << x)

/*
#ifdef BE_PLATFORM_LINUX
    #ifdef BE_BUILD_SO
        #define BENS_ENGINE_API __attribute__((visibility("default")))
    #else
        #define BENS_ENGINE_API 
    #endif
#endif
*/
