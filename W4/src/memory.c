/******************************************************************************
 * Copyright (C) 2020 - Iván Herrera
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Iván Herrera
 * @date May 17 2020
 *
 */

#include <stdint.h>
#include <stdio.h>
#include "memory.h"
#define PRINTF(...) printf(__VA_ARGS__)


/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  if(abs(dst - src) >= length){ 
    for(int i=0;i<length;i++){
      *(dst+i) = *(src+i);
      *(src + i) = 0;
    }
  }
  else if(dst < src){
    for(int i=0;i<length;i++){
      *(dst+i) = *(src+i);
      *(src + i) = 0;
    }
  }
  else if(dst > src){
    for(int i=length-1;i>=0;i--){
      *(dst+i) = *(src+i);
    }
  }
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  if(abs(dst - src >= length)){ 
    for(int i=0;i<length;i++){
      *(dst+i) = *(src+i);
    }
  }
  else if(dst < src){
    for(int i=0;i<length;i++){
      *(dst+i) = *(src+i);
    }
  }
  else if(dst > src){
    for(int i=length-1;i>0;i--){
      *(dst+i) = *(src+i);
    }
  }
  return dst;
}    

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  for(int i=0;i<length;i++){
    *(src+i) = value;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  for(int i=0;i<length;i++){
    *(src+i) = 0;
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  int x;
  if(!(length%2)){
    for(int i=0;i<length/2;i++){
      x = *(src + i);
      *(src + i) = *(src + length - 1 - i);
      *(src + length -1 - i) = x;
    }
  }
  else{
    length = length - 1;
    for(int i=0;i<length/2;i++){
      x = *(src + i);
      *(src + i) = *(src + length - i);
      *(src + length - i) = x;
    }
  }
  return src;
}

int32_t * reserve_words(size_t length){
  int32_t *src;
  src = (int32_t *)malloc(length);
  return src;
}

void free_words(int32_t * src){
  free(src);
  PRINTF("La dirección de memoria %p fue exitosamente liberada\n", src);
}
