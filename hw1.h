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

//GLOBAL VARIABLES

int negate = 0;

//enum for twiggle_bit function
typedef enum
{
    CLEAR,
    SET,
    TOGGLE
} operation_t;

//HELPER FUNCTIONS

/**
* @brief Returns the result of a number raised to an exponent
*
* @param base Base integer
* @param exp Number of times the base integer multiplies itself
*
* @return int
*/
int mathPow(int base, int exp);

//ASSIGNMENT FUNCTIONS(Implemented in the hw1.c file)

/**
* @brief Converts unsigned int to binary string.
*
* Returns -1 and sets str to empty on error
*
* @return int
*/
int uint_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits);

/**
* @brief Converts signed int to binary string.
*
* Returns -1 and sets str to empty on error
*
* @return int
*/
int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits);

/**
* @brief Converts unsigned int to hexadecimal string.
*
* Returns -1 and sets str to empty on error
*
* @return int
*/
int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits);

/**
* @brief Sets, clears or toggles a particular bit in the given input based on the operation given in the typedefenum
*
* Returns 0xFFFFFFFF on error.
*
* @return uint32_t
*/
uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation);

/**
* @brief Return the value of 3 bits from given start bit, shifted down to the end
*
* Returns 0xFFFFFFFF on error.
*
* @return uint32_t
*/
uint32_t grab_three_bits(uint32_t input, int start_bit);

/**
* @brief Prints hex representation of 8 byte increments starting from loc for nbytes
*
* Returns 0xFFFFFFFF on error.
*
* @return uint32_t
*/
char *hexdump(char *str, size_t size, const void *loc, size_t nbytes);

//TEST FUNCTIONS

/**
* @brief Tests uint_to_binstr
*
* Contains 5 test cases that tests 
* using valid and invalid parameters.
*
* @return vint
*/
int test_uint_to_binstr()
{
    // Test function return value.
    int testResult = 1;

    printf("-----------------------------------------\n");
    printf("Testing function: test_uint_to_binstr\n");
    printf("-----------------------------------------\n");

    // TestCase 1:
    int size = 18;
    int num = 35400;
    int nbits = 16;
    char *stringArr = malloc(size);
    printf("Commencing Test 1...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    int actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    int expectedResult = 18;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 2 :
    size = 10;
    num = -18;
    nbits = 6;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 2...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 3:
    size = 10;
    num = 18;
    nbits = 4;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 3...(nbits param is too small for binary representation)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 4:
    size = 7;
    num = 18;
    nbits = 5;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 4...(size param is too small to store binary string)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 7;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 5:
    size = 18;
    num = 65400;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 18;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 6:
    size = 3;
    num = 0;
    nbits = 1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 3;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 7:
    size = 2;
    num = 16;
    nbits = 1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 8:
    size = 8;
    num = 106;
    nbits = 1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 8:
    size = 10;
    num = 106;
    nbits = 7;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 9;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 9:
    size = 25;
    num = 747474;
    nbits = 20;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 22;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 9:
    size = 25;
    num = 67;
    nbits = 17;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 19;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 10:
    size = 5;
    num = 5;
    nbits = -1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    return testResult;
}

/**
 * @brief Tests int_to_binstr
 *
 * Contains test cases that tests
 * using valid and invalid parameters.
 *
 * @return int
 */
int test_int_to_binstr()
{
    int testResult = 1;

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
    int actualResult = uint_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    int expectedResult = 7;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 2:
    size = 18;
    num = -530;
    nbits = 13;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 2...()\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 15;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 3:
    size = 10;
    num = -255;
    nbits = 4;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 3...(nbits param is too small for binary representation)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 4:
    size = 8;
    num = -8;
    nbits = 5;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 4...(size param is too small to store binary string)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 7;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 5:
    size = 18;
    num = 65400;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 18;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 6:
    size = 3;
    num = 0;
    nbits = 1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 3;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 7:
    size = 2;
    num = 16;
    nbits = 1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 8:
    size = 8;
    num = 106;
    nbits = 1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 9:
    size = 10;
    num = 106;
    nbits = 7;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 9;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 10:
    size = 35;
    num = -747474;
    nbits = 32;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 34;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 11:
    size = 25;
    num = -67;
    nbits = 12;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 14;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 12:
    size = 5;
    num = 5;
    nbits = -1;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Using a large number)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    // TestCase 13:
    size = 35;
    num = -310;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...(Size is too big but null character is present)\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = int_to_binstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nBinary String: %s\n\n", actualResult, stringArr);
    expectedResult = 18;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    return testResult;
}

/**
* @brief Tests uint_to_hexstr
*
* Contains 14 test cases that tests 
* using valid and invalid parameters.
*
* @return int
*/
int test_uint_to_hexstr()
{
    int testResult = 1;

    printf("-----------------------------------------\n");
    printf("Testing function: test_int_to_hexstr\n");
    printf("-----------------------------------------\n");

    //TestCase 1: nbits=4, hex=1
    int size = 10;
    int num = 6;
    int nbits = 4;
    char *stringArr = malloc(size);
    printf("Commencing Test 1...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    int actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    int expectedResult = 3;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    //TestCase 2: nbits=4, hex<1, num=0
    size = 10;
    num = 0;
    nbits = 4;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 2...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 3;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    //TestCase 3: nbits=8, hex=2
    size = 18;
    num = 36;
    nbits = 8;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 3...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 4;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 4: nbits=8, hex<2
    size = 18;
    num = 3;
    nbits = 8;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 4...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 4;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    //TestCase 5: nbits=8, num -ve
    size = 18;
    num = -123;
    nbits = 8;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 5...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }

    //TestCase 6: nbits=16, hex=4
    size = 10;
    num = 26930;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 6...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 6;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 7: nbits=16, hex<4
    size = 10;
    num = 9;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 7...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 6;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 8: nbits=32, hex=8
    size = 20;
    num = 1203012;
    nbits = 32;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 8...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 10;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 9: nbits=32, hex<8
    size = 15;
    num = 30;
    nbits = 32;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 9...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = 10;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 10: nbits<0
    size = 15;
    num = 30;
    nbits = -12;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 10...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 11: nbits>32
    size = 15;
    num = 30;
    nbits = 35;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 11...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 12: nbits even but not a power of 2
    size = 15;
    num = 30;
    nbits = 24;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 12...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 13: num<0
    size = 35;
    num = -31;
    nbits = 8;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 13...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 14: size not enough
    size = 2;
    num = 310;
    nbits = 16;
    stringArr = realloc(stringArr, size);
    printf("Commencing Test 14...\n");
    printf("Testing with following parameters:\nsize=%i\nnum=%i\nnbits=%i\n", size, num, nbits);
    actualResult = uint_to_hexstr(stringArr, size, num, nbits);
    printf("Return value from function: %i\nHexadecimal String: %s\n\n", actualResult, stringArr);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    return testResult;
}

/**
* @brief Tests twiggle_bit
*
* Contains 6 test cases that tests 
* using valid and invalid parameters.
*
* @return int
*/
int test_twiggle_bit()
{
    printf("-----------------------------------------\n");
    printf("Testing function: test_twiggle_bit\n");
    printf("-----------------------------------------\n");
    int testResult = 1;
    //TestCase 1: operation= SET
    int num = 6;
    int bit = 4;
    operation_t operation = SET;
    printf("Commencing Test 1...\n");
    printf("Testing with following parameters:\nnum=%i\nbit=%i\noperation=%i\n", num, bit, operation);
    int actualResult = twiggle_bit(num, bit, operation);
    printf("Return value from function: %i\n\n", actualResult);
    int expectedResult = 22;

    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 2: operation =CLEAR
    num = 10;
    bit = 2;
    operation = CLEAR;
    printf("Commencing Test 2...\n");
    printf("Testing with following parameters:\nnum=%i\nbit=%i\noperation=%i\n", num, bit, operation);
    actualResult = twiggle_bit(num, bit, operation);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = 10;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 3: operation =TOGGLE
    num = 20;
    bit = 5;
    operation = TOGGLE;
    printf("Commencing Test 3...\n");
    printf("Testing with following parameters:\nnum=%i\nbit=%i\noperation=%i\n", num, bit, operation);
    actualResult = twiggle_bit(num, bit, operation);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = 52;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 4: bit < 0
    num = 20;
    bit = -5;
    operation = TOGGLE;
    printf("Commencing Test 4...\n");
    printf("Testing with following parameters:\nnum=%i\nbit=%i\noperation=%i\n", num, bit, operation);
    actualResult = twiggle_bit(num, bit, operation);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 5: bit > 31
    num = 200;
    bit = 33;
    operation = TOGGLE;
    printf("Commencing Test 5...\n");
    printf("Testing with following parameters:\nnum=%i\nbit=%i\noperation=%i\n", num, bit, operation);
    actualResult = twiggle_bit(num, bit, operation);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 6: num<0
    num = -54;
    bit = 3;
    operation = TOGGLE;
    printf("Commencing Test 6...\n");
    printf("Testing with following parameters:\nnum=%i\nbit=%i\noperation=%i\n", num, bit, operation);
    actualResult = twiggle_bit(num, bit, operation);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    return testResult;
}

/**
* @brief Tests twiggle_bit
*
* Contains 6 test cases that tests 
* using valid and invalid parameters.
*
* @return int
*/
int test_grab_three_bits()
{

    printf("-----------------------------------------\n");
    printf("Testing function: test_grab_three_bits\n");
    printf("-----------------------------------------\n");
    int testResult = 1;
    //TestCase 1: start_bit=12, input=234
    int input = 234;
    int start_bit = 3;
    printf("Commencing Test 1...\n");
    printf("Testing with following parameters:\ninput=%i\nstart_bit=%i\n", input, start_bit);
    int actualResult = grab_three_bits(input, start_bit);
    printf("Return value from function: %i\n\n", actualResult);
    int expectedResult = 5;

    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 2: start_bit<0
    input = 234;
    start_bit = -3;
    printf("Commencing Test 2...\n");
    printf("Testing with following parameters:\ninput=%i\nstart_bit=%i\n", input, start_bit);
    actualResult = grab_three_bits(input, start_bit);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;

    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 3: start_bit>29
    input = 234;
    start_bit = 30;
    printf("Commencing Test 3...\n");
    printf("Testing with following parameters:\ninput=%i\nstart_bit=%i\n", input, start_bit);
    actualResult = grab_three_bits(input, start_bit);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 4: start_bit>29
    input = 234;
    start_bit = 30;
    printf("Commencing Test 4...\n");
    printf("Testing with following parameters:\ninput=%i\nstart_bit=%i\n", input, start_bit);
    actualResult = grab_three_bits(input, start_bit);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    //TestCase 5: input<0
    input = -234;
    start_bit = 3;
    printf("Commencing Test 5...\n");
    printf("Testing with following parameters:\ninput=%i\nstart_bit=%i\n", input, start_bit);
    actualResult = grab_three_bits(input, start_bit);
    printf("Return value from function: %i\n\n", actualResult);
    expectedResult = -1;
    if (expectedResult == actualResult)
    {
        testResult = testResult && 1;
    }
    else
    {
        testResult = testResult && 0;
    }
    return testResult;
}

#endif