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
 * @file <stats.c - Implementation File> 
 * @brief <Program that performs data analysis and return statistical information about an array>
 *
 * <With this program, given an array, we can obtain the maximum, minimum, mean, and median of a data set; we can also reorder the data set from large to small. Statistical values are rounded down to the nearest integer>
 *
 * @author <Iván Herrera>
 * @date <22/04/2020>
 *
 */

#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

unsigned char sorted_array[SIZE];

int main() {
  
  course1();
  unsigned char median = 0;
  unsigned char mean = 0;
  unsigned char minimum = 0;
  unsigned char maximum = 0;
   
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test, SIZE);
  sort_Array(SIZE, test);
  median = find_median(SIZE, sorted_array);
  mean = find_mean(SIZE, test);
  maximum = find_maximum(SIZE, test);
  minimum = find_minimum(SIZE, test);
  print_statistics(median, mean, maximum, minimum);
  

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char median, unsigned char mean, unsigned char maximum, unsigned char minimum){
  PRINTF("The median is: %u, the mean is: %u, the maximum is: %u, the minimum is: %u \n", median, mean, maximum, minimum);   
}

void print_array(unsigned char test[],int size){
  int i;
  for (i=0;i < size;i++) {
  PRINTF("%u ",test[i]);
  }
  PRINTF("\n");
}

int find_median(int size, unsigned char test[]){
  unsigned char median = 0;
  int index_median = 0;
  if(size%2>0)
  {
    index_median = floor(size/2);
    median = test[index_median];
  }
  else
  {
    index_median = size/2;
    median = (test[index_median - 1] + test[index_median])/2;
  }
  return median;
}

int find_mean(int size, unsigned char test[]){
  unsigned char mean = 0;
  int suma = 0;
  for(int i = 0; i < size; i++)
  {
    suma = suma + test[i];
  }
  mean = suma/size;
  return mean;
}

int find_maximum(int size, unsigned char test[]){
  unsigned char maximum = 0;
  for(int i = 0; i < size; i++)
  {
    if (maximum < test[i])
    {
      maximum = test[i];
    }
  }
  return maximum;
}

int find_minimum(int size, unsigned char test[]){
  unsigned char minimum = 0;
  for(int i = 0; i < size; i++)
  {
    if (minimum > test[i])
    {
      minimum = test[i];
    }
  }
  return minimum;
}
  
void sort_Array(int size, unsigned char test[]) 
{ 
  for (int i = 0; i < size; i++)                  
    {
    for (int j = 0; j < size; j++)            
      {
        if (test[j] > test[i])             
	{
          int tmp = test[i];        
          test[i] = test[j];            
          test[j] = tmp;            
	}  
      }
    }
//#ifdef VERBOSE
    PRINTF("The sorted array is: \n");
    for (int n=0; n<size; n++)
    {
      printf("%u ", test[n]);
    }
    PRINTF("\n");
    
    for(int i = 0; i < size; i++)
    {
      sorted_array[i] = test[i];
    }
//#endif
}
