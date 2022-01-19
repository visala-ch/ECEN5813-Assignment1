/*******************************************************************************
* Title                 :   Assignment 1
* Author                :   Visalakshmi Chemudupati
* File Name             :   hw1.c
* Description           :   Implementation of the 6 functions for assignment 1.
* Tools used            :   Cupes compiler, VS Code

* Identification of any leveraged code

* Applicable Links      :   
Logic for int_to_binstr was implemented from this thread.
https://cboard.cprogramming.com/cplusplus-programming/43848-signed-int-binary.html

For getting last n bits of an integer (grab_three_bits):
https://stackoverflow.com/questions/8011700/how-do-i-extract-specific-n-bits-of-a-32-bit-unsigned-integer-in-c/8012148

*******************************************************************************/
#include "hw1.h"

//Get String Length.
int stringLength(char *str)
{
    unsigned i = 0;
    // Count chars until a null value is read.
    while (1)
    {
        if (str[i] == '\0')
        {
            return i;
        }
        i++;
    }
}

int mathPow(int base, int exp)
{
    if (exp < 0)
        return -1;
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

// Function 1:
// Returns the binary representation of an unsigned integer, as a null-terminated string. On input,
// str is a pointer to a char array of at least size bytes, num is the value to be converted, and nbits
// is the number of bits in the input.
// If the operation was successful, the function returns the number of characters written to str, not
// including the terminal \0. In the case of an error, the function returns a negative value, and str is
// set to the empty string
int uint_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits)
{
    //Base case:
    //Num can't be 0 bits,
    //Num can't be less than 0
    //Size cant be 0
    if ((nbits < 1) || (num > INT_MAX) || (size < 3))
    {
        str[0] = '\0';
        return -1;
    }

    //Solution:

    // Add '0b' to the start of binary string
    str[0] = '0';
    str[1] = 'b';

    int index = 2; //Taking into account of the '0b' appended at start of string

    int binaryStringValue = 0;

    unsigned i;
    for (i = 1 << (nbits - 1); i > 0; i = i >> 1)
    {
        if (num & i)
        {
            //If negate is true,
            str[index] = negate ? '0' : '1';

            //Every time we write a 1 to the string, we update the string's value.
            //This will help us compare the value to the actual num passed in.
            (binaryStringValue += i);
        }
        else
        {
            str[index] = negate ? '1' : '0';
        }

        index++;

        if (index > size)
        {
            str[0] = '\0';
            return -1;
        }
    }

    // Fail case: nbits aren't big enough.
    if (binaryStringValue != num)
    {
        str[0] = '\0';
        return -1;
    }

    str[index] = '\0'; //Null terminate the string.

    return index;
}

// Function 2:
// Returns the binary representation of a signed integer, as a null-terminated string. On input, str is
// a pointer to a char array of at least size bytes, num is the value to be converted, and nbits is the
// number of bits in the input.
// If the operation was successful, the function returns the number of characters written to str, not
// including the terminal \0. In the case of an error, the function returns a negative value, and str is
// set to the empty string.
int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits)
{

    if (num > -1)
    {
        return uint_to_binstr(str, size, num, nbits);
    }

    num *= -1;
    num -= 1;

    negate = 1;
    int result = uint_to_binstr(str, size, num, nbits);
    negate = 0; //Always set negate back to 0 after calling this function.

    //MSB is always 1 in a negative number
    if (str[2] != '1')
    {
        str[0] = '\0';
        return -1;
    }

    //If MSB is 1, the second most MSB can't be a 0.
    //If it is, the value could be positive or negative
    //since we dont have an overflow bit
    if ((str[2] == '1' && str[3] == '0'))
    {
        str[0] = '\0';
        return -1;
    }

    return result;
}

// Function 3:
// Returns the hexadecimal representation of an unsigned integer, as a null-terminated string. On
// input, str is a pointer to a char array of at least size bytes, num is the value to be converted, and
// nbits is the number of bits to be considered. Note that nbits must be one of the values 4, 8, 16,
// or 32, corresponding to 1, 2, 4, or 8 hexadecimal digits.
// If the operation was successful, the function returns the number of characters written to str, not
// including the terminal \0. In the case of an error, the function returns a negative value, and str is
// set to the empty string.
int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits)
{
    str[0] = '\0';
    int hexLength = 0;
    int index = 0, hexVal = 0;

    // Checking for invalid nbits
    if ((nbits & (nbits - 1)) || (nbits > 32) || ((nbits & (nbits - 1)) != 0))
    {
        str[0] = '\0';
        return -1;
    }
    if (num == 0)
    {
        str[index] = '0';
        hexLength++;
        index++;
    }

    while (num != 0)
    {
        hexVal = num & 0xF;
        if (hexVal < 10)
            hexVal = hexVal + 48;
        else
            hexVal = hexVal + 55;

        str[index] = hexVal;
        index++;
        hexLength++;

        if (index + 2 > size)
        {
            return -1;
        }
        num = num >> 4;
    }

    if ((nbits == 4))
    {
        if (hexLength != 1)
            str[0] = '\0';
        return -1;
    }

    if (nbits == 8)
    {
        if (hexLength > 2)
        {
            str[0] = '\0';
            return -1;
        }
        if (hexLength < 2)
        {
            str[index] = '0';
            index++;
        }
    }

    if (nbits == 16)
    {
        if (hexLength > 4)
        {
            str[0] = '\0';
            return -1;
        }
        if (hexLength < 4)
        {
            for (int i = 4 - hexLength; i > 0; i--)
            {
                str[index] = '0';
                index++;
            }
        }
    }

    if (nbits == 32)
    {
        if (hexLength > 8)
        {
            str[0] = '\0';
            return -1;
        }
        if (hexLength < 8)
        {
            for (int i = 8 - hexLength; i > 0; i--)
            {
                str[index] = '0';
                index++;
            }
        }
    }

    str[index] = 'x';
    str[index + 1] = '0';
    str[index + 2] = '\0';

    // Since str now contains the desired string in reverse,
    // we copy it to a temporary variable, reversedString which has the same size.
    char reverseString[size];
    int i = 0;
    for (i = 0; i < index + 2; i++)
    {
        reverseString[i] = str[index + 1 - i];
    }
    reverseString[i] = '\0';
    //Mental note: This does NOT work for char arrays.
    // str = reverse;

    // Copying the reversed string to str.
    i = 0;
    while (reverseString[i] != '\0')
    {
        str[i] = reverseString[i];
        i++;
    }

    return index + 2;
}

// Function 4:
// Changes a single bit of the input value, without changing the other bits.
// Upon invocation, bit is in the range 0 to 31, inclusive. Returns 0xFFFFFFFF
// in the case of an error.
uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation)
{
    char hexArray[32] = "";
    *hexArray = (char)input;

    //invalid bit
    if (bit < 0 || bit > 31)
    {
        return 0xFFFFFFFF;
    }
    // negative input
    // checking with INT_MAX because inpput is of type uint
    // which automatically upgrades any -ve value to max integer value
    if (input > INT_MAX)
    {
        return 0xFFFFFFFF;
    }

    // Checking if input is bin, int or hex
    if (hexArray[1] == 'x')
    {
        uint_to_hexstr(hexArray, 32, input, 32);
    }

    // Twiggle bits based on the operation type
    switch (operation)
    {
    case SET:
        input = input | (1 << bit);
        return input;
        break;
    case CLEAR:
        input = input & (~(1 << bit));
        return input;
        break;
    case TOGGLE:
        input = input ^ (1 << bit);
        return input;
        break;
    default:
        return -1;
        break;
    }
    return input;
}

// Function 5:
// Returns three bits from the input value, shifted down. This function’s output is best shown
// graphically. If start_bit is 20 and the 32-bit input is represented in binary as follows:
// ........ .XXX.... ........ ........
// Then the output would be the three bits represented by the Xs, also in binary:
// 00000000 00000000 00000000 00000XXX
// Note that start_bit represents the least-significant of the three bits of interest.
// Returns 0xFFFFFFFF on error.
uint32_t grab_three_bits(uint32_t input, int start_bit)
{

    // uint shifted_num=0;
    // Max start_bit val can be 29
    if ((start_bit < 0) || (start_bit > 29))
    {
        return -1;
    }

    // Checking for a negative input:
    // Checking with INT_MAX because input is of type uint,
    // which automatically upgrades any -ve value to max integer value
    if (input > INT_MAX)
    {
        return 0xFFFFFFFF;
    }
    input = input >> start_bit;
    input = input & 0x07; //(1<<3)-1 (This logic is given credit above.)
    return input;
}

//Function 6:
char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
{
    int lineNumber = 0;
    int index = 0;
    // uint8_t *buffer = (uint8_t *)loc;
    for (int i = 0; i < nbytes; i = i + 16)
    {
        unsigned char tempStr[6];
        uint_to_hexstr((char *)tempStr, 6, lineNumber, 16);
        lineNumber = lineNumber + 16;
        //loop to write all hex digits to str for col 1
        for (int k = 0; k < 6; k++)
        {
            str[k] = tempStr[k];

            index++;
        }
        str[index++] = '\n';
    }
    return str;
}

int main()
{
    test_uint_to_binstr();

    // test_int_to_binstr();

    // test_uint_to_hexstr();

    return 0;
}