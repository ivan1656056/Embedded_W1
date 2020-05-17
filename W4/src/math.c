/******************************************************************************/
/**
 * @file math.c
 * @brief Custom made floor and pow functions
 *
 * This file contains the implementation of custom floor and pow functions
 *
 * @author Iván Herrera
 * @date May 17 2020
 *
 */

#include "math.h"

int floor(int x){
  return (int)x;
}

int pow(int number, int power){
  int output = 1;
  for(int i = 0;i<power;i++)
  {
    output = output*number;
  }
  return output;
}
