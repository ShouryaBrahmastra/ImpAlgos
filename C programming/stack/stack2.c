/**
 * @file stack2.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Write a program in c that will reverse all words of a given line using stack as an auxiliary data structure.
 **
 **  Input: A line of text
 **  Output: A line of text
 **
 **  Example:
 **
 **  Input: abcd xyz
 **  Output: dcba zyx
 *
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>
#include <string.h>

/*Global variable access*/
int top = -1;
int cap;

int output(char a[1000], char n[])
{
    int i;

    cap = strlen(n);

    n[(strlen(n))] = ' ';

    for (i = 0; i < (strlen(n)); i++)
    {
        char ch = n[i];
        /*If any space is encountered*/
        if (ch != ' ')
        {
            /*pushing the characters into stack*/
            if ((top) < (cap - 1))
            {
                a[++top] = ch;
            }
            else
            {
                printf("Stack Overflow");
            }
        }
        else
        {
            while (top >= 0)
            {
                if (top == -1)
                {
                    printf("Stack Underflow");
                    return 1;
                }
                else
                {
                    /*printing the characters by poping method */
                    printf("%c", a[top--]);
                }
            }
            printf(" ");
        }
    }

    while (top >= 0)
    {
        if (top == -1)
        {
            printf("Stack Underflow");
            return 1;
        }
        else
        {
            /*printing the characters by poping method */
            printf("%c", a[top--]);
        }
    }
}

/*Driver program*/
int main(void)
{

    char n[10000];
    char a[cap];

    /*Taking the input*/
    scanf("%[^\n]s", n);

    output(a, n);

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// abcd xyz
// dcba zyx

*/