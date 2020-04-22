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
 * @file <Array Statistics - Implementation File> 
 * @brief <Program that performs data analysis and return statistical information about an array>
 *
 * <With this program, given an array, we can obtain the maximum, minimum, mean, and median of a data set; we can also reorder the data set from large to small. Statistical values are rounded down to the nearest integer>
 *
 * @author <Iván Herrera>
 * @date <22/04/2020>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */

void print_statistics(int median, int mean, int maximum, int minimum){

}

void print_array(int size, unsigned char test[]){
    
}

int find_median(int size, unsigned char test[]){
    
}

int find_mean(int size, unsigned char test[]){
    
}

int find_maximum(int size, unsigned char test[]){
    
}

int find_minimum(int size, unsigned char test[]){
    
}

int sort_Array(unsigned char test[]){
    
}

