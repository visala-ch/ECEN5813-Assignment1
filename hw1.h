/**
 * @file hw1.h
 * @brief An abstraction for memory read and write operations
 *
 * This header file provides an abstraction of helper and test functions
 *
 * @author Visalakshmi Chemudupati
 * @date January 18th, 2022
 * @version 1.0
 *
 */

#ifndef HW1_H
// #define FUNCTIONS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// GLOBAL VARIABLES

int negate = 0;

// enum for twiggle_bit function
typedef enum
{
    CLEAR,
    SET,
    TOGGLE
} operation_t;

// HELPER FUNCTIONS

/**
 * @brief Returns the result of a number raised to an exponent
 *
 * @param base Base integer
 * @param exp Number of times the base integer multiplies itself
 *
 * @return int
 */
int mathPow(int base, int exp);

// ASSIGNMENT FUNCTIONS(Implemented in the hw1.c file)
int uint_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits);
int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits);
int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits);
uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation);
uint32_t grab_three_bits(uint32_t input, int start_bit);
// int uint_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits);

// TEST FUNCTIONS

/**
 * @brief Tests uint_to_binstr
 *
 * Contains 5 test cases that tests
 * using valid and invalid parameters.
 *
 * @return void
 */
void test_uint_to_binstr()
{

    printf("-----------------------------------------\n");
    printf("Testing function: test_uint_to_binstr\n");
    printf("-----------------------------------------\n");

    // TestCase 1:
    int size = 18;
    int num = 35400;
    int nbits = 16;
    char *stringArr = malloc(size);
    printf("Commencing Test 1...(Simple case. Should not fail.)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", uint_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 2 : size = 10;
    num = -18;
    nbits = 6;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 2...(Invalid num)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", uint_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 3:
    size = 10;
    num = 18;
    nbits = 4;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 3...(nbits param is too small for binary representation)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", uint_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 4:
    size = 4;
    num = 18;
    nbits = 5;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 4...(size param is too small to store binary string)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", uint_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 5:
    size = 18;
    num = 65400;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", uint_to_binstr(stringArr, size, num, nbits), stringArr);
}

/**
 * @brief Tests int_to_binstr
 *
 * Contains 5 test cases that tests
 * using valid and invalid parameters.
 *
 * @return void
 */
void test_int_to_binstr()
{

    printf("-----------------------------------------\n");
    printf("Testing function: test_int_to_binstr\n");
    printf("-----------------------------------------\n");

    // //TestCase 1:
    int size = 10;
    int num = 18;
    int nbits = 5;
    char *stringArr = malloc(size);
    printf("Commencing Test 1...(Simple case. Should not fail.)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", int_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 2:
    size = 18;
    num = -530;
    nbits = 12;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 2...()\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", int_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 3:
    size = 10;
    num = -255;
    nbits = 4;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 3...(nbits param is too small for binary representation)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", int_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 4:
    size = 6;
    num = -8;
    nbits = 5;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 4...(size param is too small to store binary string)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", int_to_binstr(stringArr, size, num, nbits), stringArr);

    // TestCase 5:
    size = 35;
    num = -310;
    nbits = 11;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Size is too big but null character is present)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", int_to_binstr(stringArr, size, num, nbits), stringArr);
}

/**
 * @brief Tests uint_to_hexstr
 *
 * Contains 5 test cases that tests
 * using valid and invalid parameters.
 *
 * @return void
 */
void test_uint_to_hexstr()
{

    printf("-----------------------------------------\n");
    printf("Testing function: test_int_to_binstr\n");
    printf("-----------------------------------------\n");

    // //TestCase 1:
    int size = 10;
    int num = 18;
    int nbits = 8;
    char *stringArr = malloc(size);
    printf("Commencing Test 1...(Simple case. Should not fail.)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", uint_to_hexstr(stringArr, size, num, nbits), stringArr);

    // //TestCase 2:
    // size = 18;
    // num = -530;
    // nbits = 8;
    // stringArr = realloc(stringArr, size);
    // printf("Commencing Test 2...()\n");
    // printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    // printf("Return value from function: %i\nHexadecimal String: %s\n\n", uint_to_hexstr(stringArr, size, num, nbits), stringArr);

    // //TestCase 3:
    // size = 10;
    // num = -255;
    // nbits = 16;
    // stringArr = realloc(stringArr, size);
    // printf("Commencing Test 3...(nbits param is too small for binary representation)\n");
    // printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    // printf("Return value from function: %i\nHexadecimal String: %s\n\n", uint_to_hexstr(stringArr, size, num, nbits), stringArr);

    // //TestCase 4:
    // size = 15;
    // num = -8;
    // nbits = 32;
    // stringArr = realloc(stringArr, size);
    // printf("Commencing Test 4...(size param is too small to store binary string)\n");
    // printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    // printf("Return value from function: %i\nHexadecimal String: %s\n\n", uint_to_hexstr(stringArr, size, num, nbits), stringArr);

    // //TestCase 5:
    // size = 35;
    // num = -310;
    // nbits = 11;
    // stringArr = realloc(stringArr, size);
    // printf("Commencing Test 5...(Size is too big but null character is present)\n");
    // printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    // printf("Return value from function: %i\nHexadecimal String: %s\n\n", uint_to_hexstr(stringArr, size, num, nbits), stringArr);
}

#endif