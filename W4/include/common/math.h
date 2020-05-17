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
 * @file math.h
 * @brief Custom made math library
 *
 * Header file that provides custom pow and floor functions from math library 
 *
 * @author Iván Herrera
 * @date May 17 2020
 *
 */
#ifndef __MATH_H__
#define __MATH_H__

/**
 * @brief Program that returns the result of a^x
 * 
 * Takes base and number argument to return base^number 
 *
 * @param base Number that will be powered
 * @param number Number that will be the exponential of the base
 *
 * @return int
 */

int pow(int base, int number);

/**
 * @brief Mathematical floor function
 * 
 * Down rounds a number, dropping the decimals
 *
 * @param x Number that will be down rounded
 *
 * @return int
 */

int floor(int x);

#endif /* __MATH_H__ */
