/**
 * @ Author: MMMM
 * @ Create Time: 2024-02-28 11:21:07
 * @ Modified time: 2024-02-28 16:45:13
 * @ Description:
 * 
 * Some helper math functions.
 */

#ifndef UTILS_MATH_
#define UTILS_MATH_

#include <math.h>

/**
 * //
 * ////
 * //////    Math helper functions
 * ////////
 * ////////// 
*/

/**
 * This is a hash function that extends one of the ones given here: 
 *    http://www.cse.yorku.ca/~oz/hash.html
 * 
 * @param   { char * }  sKey  The string to perform a hash on.
 * @param   { int }     dMax  The upper limit of the resulting hash value.
 * @return  { int }           The hash value within the specified range.
*/
int Math_hash(char *sKey, int dMax) {
  unsigned long long dHash = 0;
  
  // Increment the pointer so we iterate over the string
  while (*sKey) {
    
    // Note that all this does is multiply hash by 65599 (a large prime number that works well for hashing)
    // Essentially, we have
    //    (1) << 6 means * 2^6 or 64, multtiplied to hash
    //    (2) << 16 means * 2^16 or 65536, multiplied to hash
    //    (3) - hash
    // All in all we have (64 + 65536 - 1) * hash or 65599 * hash
    dHash = (dHash << 6) + (dHash << 16) - dHash + 
      (*sKey) * (dHash % 2 ? (*sKey << 1) + (*sKey) + 1 : (*sKey) >> 1);
    sKey++;
  }

  return (int) (dHash % dMax);
}

/**
 * Linear interpolation function.
*/
float Math_lerp(float fStart, float fEnd, float fAmount) {
  //! to implement

  return 0;
}

/**
 * An easing function used to make a value approach another value smoothly.
 * We use a logarithmic speed system (since the rate of change here is proportional to 1/x,
 *    and the integral of that happens to be ln(x)).
*/
float Math_ease(float fValue, float fTarget, float fSpeed) {
  // ! to implement

  return 0;
}

#endif