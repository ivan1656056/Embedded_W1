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
 * @file data.c
 * @brief integer to string conversion and viceversa
 *
 * This file allows data conversion from signed integer to string (base 2 - 16) 
 * and viceversa utilizing pointer arythmetic
 * 
 * @author Iván Herrera
 * @date May 12, 2020
 *
 */

/* Function definitions */

#include "data.h"

uint8_t my_itoa(int32_t data, uint32_t * ptr, uint32_t base){
  static int8_t k;
  static int8_t once;
  static int8_t digits;
  static int8_t negativo;
  if(once!=1){ // Initialization - Is made only once
    if((base<2)||(base>16)){ // Sets the value of unaccepted bases to nearest  acceptable value
      if(base<2){
        base = 2;
      }
      else if(base>16){
        base = 16;
      }
    }
    if(data<0){ // Decides whether if the data is positive or negative
      negativo = 1;
      data *= -1; // Makes data positive for processing purposes
      k = 1; // Indexing must start at 1 so index 0 can be '-'
      *ptr = '-'; // Sets index 0 to '-'
    }
    else{
      negativo = 0;
      k = 0; // Indexing starts at 0
    }
    // Obtains number of digits in the data
    int32_t test=data;
    digits = 0;
    while ((test /= 10) && ++digits);
    once = 1;
    digits++;
    //printf("\nDigits: %d",digits); // Prints number of digits
  }
  // Converting part of the function
  if(data){
    my_itoa(data/base,ptr,base); // Recursive calling
    //ptrs[i] = ptr+i;
    //printf("\nData: %d i: %d\n",data,i);
    *(ptr+k) = "0123456789ABCDEF"[data%base]; // Converts remainder to bases 2 - 16 in char format
    //printf("%c",*(ptr+i));
    k++;
  }
  else{
    once = 0;
    return k;
  }
}

int32_t my_atoi(uint32_t *ptr, uint8_t digits, uint32_t base){
  int32_t valor = 0; // Initiates final storage variable
  int8_t data[digits]; // Creates an array to store individual characters of given string
  int8_t start, negativo;
  if(*(ptr) == '-'){
    start = 1;
    negativo = 1;
  }
  else{
    start = 0;
    negativo = 0;
  }
  // Converts A, B, C, E, F to 10, 11, 12, 13, 14, and 15; respectively
  for(int8_t i = 0;i<digits-start;i++){
    if(*(ptr+i+start)=='A'){
      data[i] = 10;
    }
    else if(*(ptr+i+start)=='B'){
      data[i] = 11;
    }
    else if(*(ptr+i+start)=='C'){
      data[i] = 12;
    }
    else if(*(ptr+i+start)=='D'){
      data[i] = 13;
    }
    else if(*(ptr+i+start)=='E'){
      data[i] = 14;
    }
    else if(*(ptr+i+start)=='F'){
      data[i] = 15;
    }
    // Converts value from char to int
    else{
      data[i] = *(ptr+i+start) - '0';
    }
    // printf("%d ",data[i]);
  }
  // Convertion algorithm from any base 2 - 16, to decimal
  for(int8_t i = 0; i<digits-start; i++){
    // printf("\n%d",valor);
    valor = valor + pow(base,digits-i-1-start)*data[i];
  }
  if(negativo){
    valor *= -1;
  }
  return valor; // Returns decimal int32_t value
}
