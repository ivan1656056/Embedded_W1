/******************************************************************************
 * Copyright (C) 2020 by Iván Herrera
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Iván Herrera
 * @date May 17 2020
 *
 */

#include <stdlib.h>
#include "math.h"
#include "stats.h"
#include "data.h"
#include "platform.h"
#include "course1.h"

#ifdef COURSE1
  course1();
#endif
