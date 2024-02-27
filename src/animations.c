/**
 * @ Author: MMMM
 * @ Create Time: 2024-02-25 10:46:20
 * @ Modified time: 2024-02-27 11:11:53
 * @ Description:
 * 
 * This file contains definitions for animation handlers (basically,
 *    functions that increment the animation over time).
 */

#include "./utils/utils.animation.h"
#include "./utils/utils.types.h"

#include <math.h>
#include <stdlib.h>

/**
 * //
 * ////
 * //////    Animation handlers
 * ////////
 * ////////// 
*/

void AnimationHandler_intro(p_obj Args_Animation) {
  Animation *this = (Animation *) Args_Animation;

  this->fStates[0] -= (this->fStates[0] - this->dStates[0]) / 5;
  this->fStates[1] -= (this->fStates[1] - this->dStates[1]) / 5;

  this->fStates[2] -= (this->fStates[2] - this->dStates[2]) / 5;
  this->fStates[3] -= (this->fStates[3] - this->dStates[3]) / 5;

  if(this->dT % 24 == 0) {
    this->dStates[0] = rand() % IO_getWidth();
    this->dStates[1] = rand() % IO_getHeight();
  } else if(this->dT % 24 == 12) {
    this->dStates[2] = rand() % IO_getWidth();
    this->dStates[3] = rand() % IO_getHeight();
  }
}