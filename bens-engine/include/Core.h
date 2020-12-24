#pragma once

#ifdef __linux__ 
    //linux code goes here
    #define BENS_ENGINE_API __attribute__((visibility("default")))
    // windows code goes here
#else
#error Bens Engine only supports Linux!
#endif

/*
#ifdef BE_PLATFORM_LINUX
    #ifdef BE_BUILD_SO
        #define BENS_ENGINE_API __attribute__((visibility("default")))
    #else
        #define BENS_ENGINE_API 
    #endif
#endif
*/
