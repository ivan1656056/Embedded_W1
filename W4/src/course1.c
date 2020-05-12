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
 * @file course1.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */

#include <stdint.h>
#include "course1.h"
#include "platform.h"
#include "memory.h"
#include "data.h"
#include "stats.h"

int8_t test_data1() {
  uint8_t * ptr;
  int32_t num = -4096;
  uint32_t digits;
  int32_t value;

  PRINTF("\ntest_data1();\n");
  ptr = (uint8_t*) reserve_words( DATA_SET_SIZE_W );

  if (! ptr )
  {
    return TEST_ERROR;
  }

  digits = my_itoa( num, ptr, BASE_16);   
  value = my_atoi( ptr, digits, BASE_16);
  #ifdef VERBOSE
  PRINTF("  Initial number: %d\n", num);
  PRINTF("  Final Decimal number: %d\n", value);
  #endif
  free_words( (uint32_t*)ptr );

  if ( value != num )
  {
    return TEST_ERROR;
  }
  return TEST_NO_ERROR;
}

int8_t test_data2() {
  uint8_t * ptr;
  int32_t num = 123456;
  uint32_t digits;
  int32_t value;

  PRINTF("test_data2():\n");
  ptr = (uint8_t*) reserve_words( DATA_SET_SIZE_W );

  if (! ptr )
  {
    return TEST_ERROR;
  }

  digits = my_itoa( num, ptr, BASE_10);
  value = my_atoi( ptr, digits, BASE_10);
  #ifdef VERBOSE
  PRINTF("  Initial Decimal number: %d\n", num);
  PRINTF("  Final Decimal number: %d\n", value);
  #endif
  free_words( (uint32_t*)ptr );

  if ( value != num )
  {
    return TEST_ERROR;
  }
  return TEST_NO_ERROR;
}

int8_t test_memmove1() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memmove1() - NO OVERLAP\n");
  set = (uint8_t*) reserve_words( MEM_SET_SIZE_W );

  if (! set ) 
  {
    return TEST_ERROR;
  }
  
  ptra = &set[0];
  ptrb = &set[16];
  
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 16] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memmove2() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memmove2() -OVERLAP END OF SRC BEGINNING OF DST\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);

  if (! set )
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[8];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i + 8] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memmove3() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memove3() - OVERLAP END OF DEST BEGINNING OF SRC\n");
  set = (uint8_t*)reserve_words( MEM_SET_SIZE_W);

  if (! set ) 
  {
    return TEST_ERROR;
  }
  ptra = &set[8];
  ptrb = &set[0];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++)
  {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memmove(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i] != (i + 8))
    {
      ret = TEST_ERROR;
    }
  }


  free_words( (uint32_t*)set );
  return ret;

}

int8_t test_memcopy() {
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memcopy()\n");
  set = (uint8_t*) reserve_words(MEM_SET_SIZE_W);

  if (! set ) 
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memcopy(ptra, ptrb, TEST_MEMMOVE_LENGTH);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  {
    if (set[i+16] != i)
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_memset() 
{
  uint8_t i;
  uint8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  PRINTF("test_memset()\n");
  set = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! set )
  {
    return TEST_ERROR;
  }
  ptra = &set[0];
  ptrb = &set[16];

  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B; i++) 
  {
    set[i] = i;
  }

  print_array(set, MEM_SET_SIZE_B);
  my_memset(ptra, MEM_SET_SIZE_B, 0xFF);
  print_array(set, MEM_SET_SIZE_B);
  my_memzero(ptrb, MEM_ZERO_LENGTH);
  print_array(set, MEM_SET_SIZE_B);
  
  /* Validate Set & Zero Functionality */
  for (i = 0; i < MEM_ZERO_LENGTH; i++)
  {
    if (set[i] != 0xFF)
    {
      ret = TEST_ERROR;
    }
    if (set[16 + i] != 0)
    {
      ret = TEST_ERROR;
    }
  }
  
  free_words( (uint32_t*)set );
  return ret;
}

int8_t test_reverse()
{
  uint8_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * copy;
  uint8_t set[MEM_SET_SIZE_B] = {0x3F, 0x73, 0x72, 0x33, 0x54, 0x43, 0x72, 0x26,
                                 0x48, 0x63, 0x20, 0x66, 0x6F, 0x00, 0x20, 0x33,
                                 0x72, 0x75, 0x74, 0x78, 0x21, 0x4D, 0x20, 0x40,
                                 0x20, 0x24, 0x7C, 0x20, 0x24, 0x69, 0x68, 0x54
                               };

  PRINTF("test_reverse()\n");
  copy = (uint8_t*)reserve_words(MEM_SET_SIZE_W);
  if (! copy )
  {
    return TEST_ERROR;
  }
  
  my_memcopy(set, copy, MEM_SET_SIZE_B);

  print_array(set, MEM_SET_SIZE_B);
  my_reverse(set, MEM_SET_SIZE_B);
  print_array(set, MEM_SET_SIZE_B);

  for (i = 0; i < MEM_SET_SIZE_B; i++)
  {
    if (set[i] != copy[MEM_SET_SIZE_B - i - 1])
    {
      ret = TEST_ERROR;
    }
  }

  free_words( (uint32_t*)copy );
  return ret;
}

void course1(void) 
{
  uint8_t i;
  int8_t failed = 0;
  int8_t results[TESTCOUNT];

  results[0] = test_data1();
  results[1] = test_data2();
  results[2] = test_memmove1();
  results[3] = test_memmove2();
  results[4] = test_memmove3();
  results[5] = test_memcopy();
  results[6] = test_memset();
  results[7] = test_reverse();

  for ( i = 0; i < TESTCOUNT; i++) 
  {
    failed += results[i];
  }

  PRINTF("--------------------------------\n");
  PRINTF("Test Results:\n");
  PRINTF("  PASSED: %d / %d\n", (TESTCOUNT - failed), TESTCOUNT);
  PRINTF("  FAILED: %d / %d\n", failed, TESTCOUNT);
  PRINTF("--------------------------------\n");
}

uint8_t my_itoa(int32_t data, int32_t * ptr, uint32_t base){
    static int8_t k;
    static int8_t once;
    static int8_t digits;
    static int8_t negativo;
    if(once!=1){ // Initialization - Is made only once
        if((base<2)||(base>16)) // Sets the value of unaccepted bases to nearest acceptable value
        {
            if(base<2){
                printf("La base introducida es inválida, se ha cambiado a base 2");
                base = 2;
            }
            else if(base>16){
                printf("La base introducida es inválida, se ha cambiado a base 16");
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
    return k;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){
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
    for(int8_t i = 0; i<digits; i++){
        // printf("\n%d",valor);
        valor = valor + pow(base,digits-i-1-start)*data[i];
    }
    if(negativo){
        valor *= -1;
    }
    return valor; // Returns decimal int32_t value
}
