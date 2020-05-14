/******************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
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
