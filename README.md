# ECEN5813-Assignment1
Code for Assignment 1 for PES, ECEN5813, Spring 2022

Developing a C program using the below six functions, with different functionalities

Int uint_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits) :
Function to convert signed integer to binary string using given parameters

int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits):
Function to convert unsigned integer to binary string using given parameters

int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits):
 Function to convert an unsigned integer to hexadecimal string

uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation):
 Function to SET, CLEAR, or TOGGLE a single bit in an input based on the operation given

uint32_t grab_three_bits(uint32_t input, int start_bit)
Function to grab three bits from the start bit, shifted down

char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
Function to return a string representing a dump of  nbytes of memory starting at loc.

To build: 
To build the code, the following commands are used: 
gcc -Wall -Werror hw1.c -o hw1

To run:
./hw1

