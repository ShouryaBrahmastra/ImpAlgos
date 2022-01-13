/**
 * @file decimal-binary.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 ** C program to convert user given decimal number into binary number
 *
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>
#include <stdlib.h>

#define MAXBITS 100

int binary(int inputNumber)
{
    // for the remainder
    int re;

    // contains the bits 0/1
    int bits[MAXBITS];

    // for the loops
    int j;
    int i = 0;

    // make sure the input number is a positive integer.
    if (inputNumber < 0)
    {
        printf("only positive integers >= 0\n");
        return 0;
    }

    // actual processing
    while (inputNumber > 0)
    {
        // computes the remainder by modulo 2
        re = inputNumber % 2;

        // computes the quotient of division by 2
        inputNumber = inputNumber / 2;

        bits[i] = re;
        i++;
    }

    // iterates backwards over all bits
    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", bits[j]);
    }

    // for the case the input number is 0
    if (i == 0)
    {
        printf("0");
    }
}

int main(void)
{
    // input of the user
    int inputNumber;

    // reads a decimal number from the user.
    printf("Enter a positive integer number: ");
    scanf("%d", &inputNumber);

    binary(inputNumber);

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// Enter a positive integer number: 9
// 1001

*/