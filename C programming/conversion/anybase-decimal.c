/**
 * @file anybase-decimal.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 ** convert from any base to decimal
 *
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <ctype.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void decimal(int base, char *number)
{
    int i, j;
    unsigned long decimal = 0;

    for (i = 0; number[i] != '\0'; i++)
    {
        if (isdigit(number[i]))
            number[i] -= '0';
        else if (isupper(number[i]))
            number[i] -= 'A' - 10;
        else if (islower(number[i]))
            number[i] -= 'a' - 10;
        else
            number[i] = base + 1;

        if (number[i] >= base)
        {
            printf("invalid number\n");
        }
    }

    for (j = 0; j < i; j++)
    {
        decimal *= base;
        decimal += number[j];
    }

    printf("%lu\n", decimal);
}

int main(void)
{
    int base;
    char number[100];

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the number: ");
    scanf("%s", &number[0]);

    decimal(base, number);

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// Enter the base: 16
// Enter the number: 11A
// 282

*/