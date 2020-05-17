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
 * @file <Array Statistics - Header File> 
 * @brief <Program that performs data analysis and return statistical information about an array>
 *
 * <With this program, given an array, we can obtain the maximum, minimum, mean, and median of a data set; we can also reorder the data set from large to small. Statistical values are rounded down to the nearest integer>
 *
 * @author <Iván Herrera>
 * @date <22/04/2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_statistics(unsigned char median, unsigned char mean, unsigned char maximum, unsigned char minimum);
/**
 * @brief <Prints the obtained values>
 *
 * <Prints the statistical values obtained through the analysis>
 *
 * @param <median <median value of the array>
 * @param <mean> <mean value of the array>
 * @param <maximum> <maximum value of the array>
 * @param <minimum> <minimum value of the array>
 *
 * @return <Screen prints the statistical values using "printf", doesn't return value>
 */

/* Add Your Declarations and Function Comments here */ 
void print_array(unsigned char test[], int size);
/**
 * @brief <Prints the test array>
 *
 * <Prints all the values of the array that we work on>
 *
 * @param <size> <number of elements that the test array has>
 * @param <test[]> <data array that we analize>
 *
 * @return <Screen prints the values of the array using "printf", doesn't return value>
 */

/* Add Your Declarations and Function Comments here */ 
int find_median(int size, unsigned char test[]);
/**
 * @brief <Obtains median>
 *
 * <Obtains the statistical median of the data array "test">
 *
 * @param <size> <number of elements that the test array has>
 * @param <test[]> <data array that we analize>
 *
 * @return <int median>
 */

/* Add Your Declarations and Function Comments here */ 
int find_mean(int size, unsigned char test[]);
/**
 * @brief <Obtains mean>
 *
 * <Obtains the statistical mean of the data array "test">
 *
 * @param <size> <number of elements that the test array has>
 * @param <test[]> <data array that we analize>
 *
 * @return <int mean>
 */

/* Add Your Declarations and Function Comments here */ 
int find_maximum(int size, unsigned char test[]);
/**
 * @brief <Obtains maximum>
 *
 * <Obtains the statistical maximum of the data array "test">
 *
 * @param <size> <number of elements that the test array has>
 * @param <test[]> <data array that we analize>
 *
 * @return <int maximum>
 */

/* Add Your Declarations and Function Comments here */ 
int find_minimum(int size, unsigned char test[]);
/**
 * @brief <Obtains minimum>
 *
 * <Obtains the statistical minimum of the data array "test">
 *
 * @param <size> <number of elements that the test array has>
 * @param <test[]> <data array that we analize>
 *
 * @return <int minimum>
 */

/* Add Your Declarations and Function Comments here */ 
void sort_Array(int size, unsigned char test[]);
/**
 * @brief <Sorts the array from largest to smallest>
 *
 * <Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)>
 *
 * @param <test[]> <data array that we analize>
 *
 * @return <unsigned char sorted[SIZE]>
 */

#endif /* __STATS_H__ */
