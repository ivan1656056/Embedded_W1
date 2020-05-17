/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h 
 * @brief This file is to be used to course 1 final assessment. Includes function declarations of my_itoa and my_atoi
 *
 * @author Iván Herrera
 * @date May 12, 2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <math.h>

/**
 * @brief Program that returns string from integer value
 * 
 * Converts signed 32 bit decimal integer to any base from 2 to 16 string, and stores it at an address
 *
 * @param data Variable that stores data to be converted
 * @param ptr Address where string will be stored
 * @param base Numerical base to which number will be converted to
 *
 * @return void
 */

uint8_t my_itoa(int32_t data, uint32_t * ptr, uint32_t base);

/**
 * @brief Program that returns string from integer value
 * 
 * Converts signed 32 bit decimal integer to any base from 2 to 16 string, and stores it at an address
 *
 * @param ptr Address where string to be converted is stored
 * @param digits Number of digits in the character set
 * @param base Numerical base in which the string is written
 *
 * @return void
 */

int32_t my_atoi(uint32_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
