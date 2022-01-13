/**
 * @file stack3.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Write a program in C that will check if the parentheses/Square brackets/Curly brackets are well formed
 **  [ i.e. the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct ] in an infix expression.
 **  Print 1 if the given infix expression is well balanced brackets otherwise print 0.
 **
 **  Example:
 **
 **  Input: {(p+q) * (a+b)}
 **  Output: 1
 **
 **  Input: {(p+q) * }a+b)}
 **  Output: 0
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

int point = -1;

/*The driver code*/
int main(void)
{
    int size, i;
    char str[40], stack[40];

    /*initialising the stack*/
    /*Taking the input from the user*/
    scanf("%[^\n]s", str);

    size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[')) /*pushing to stack if bracket is opening*/
        {
            point++;
            stack[point] = str[i];
        }
        else if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']')) /*popping from stack if bracket is closing*/
        {
            point--;
        }
    }
    if (point == -1) /*True if stack is empty*/
    {
        printf("1");
        return 0;
    }
    printf("0"); /*False if stack is not empty*/

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// {(p+q) * (a+b)}
// 1

// Test Case 2:-
// {(p+q) * }a+b)}
// 0

*/