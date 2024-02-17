/**
 * This makes sure we have the same type names in both Windows and Unix,
 *    even though under the hood they're (just a bit) different.
*/

#ifndef UTILS_TYPES_UNIX
#define UTILS_TYPES_UNIX

// We're gonna get some types here
#include <pthread.h>

// A handle is just a pointer
// It's a Windows convention (?) but also we're overriding them with Unix data types here

// Pointers
typedef void *Handle;                     // A handle to any object we wish
typedef Handle HandleSTD;                 // IO handles
typedef pthread_t *HandleThread;          // A pointer to a thread
typedef pthread_mutex_t *HandleMutex;     // A pointer to a mutex

// FOR THE CODE BELOW (parameter object pointers):
// Note that we have to do this because some of the Windows API requires us to pass
//    both a callback and its arguments separately. The data types here are primarily
//    for representing the arguments to a callback function.

// Parameter object pointers
typedef void *Param;                      // A pointer to a collection of function parameters
typedef Param ParamInt;                   // An integer to be passed as an argument
typedef Param ParamStr;                   // A string to be passed as an argument
typedef Param ParamObj;                   // A pointer to a struct to be passed to a function
typedef void (*ParamFunc)(void *pArgs);   // A pointer to a callback function

#endif