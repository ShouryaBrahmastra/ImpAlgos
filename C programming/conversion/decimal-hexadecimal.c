/**
 * @file decimal-hexadecimal.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 ** C program to convert user given decimal number into hexadecimal
 *
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>

void hexa(long int decimalNumber)
{

    long remainder, quotient;
    int i = 1, j, temp;
    char hexadecimalNumber[100];

    quotient = decimalNumber;
    while (quotient != 0)
    {
        temp = quotient % 16;
        // To convert integer into character
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }
    printf("Equivalent hexadecimal value is : ");
    // Displaying the converted hexa value
    for (j = i - 1; j > 0; j--)
        printf("%c", hexadecimalNumber[j]);
}

int main(void)
{
    long int decimalNumber;
    char hexadecimalNumber[100];

    printf("Enter any decimal number: ");
    scanf("%ld", &decimalNumber);

    hexa(decimalNumber);

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// Enter any decimal number: 69
// Equivalent hexadecimal value is : 45

*/