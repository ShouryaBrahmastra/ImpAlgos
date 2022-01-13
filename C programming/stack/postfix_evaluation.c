/**
 * @file postfix_evaluation.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  You are given an expression (postfix). The expression may contain multiple digits as well as single digit with different operators. Each of the digits (single or multiple) and operators are separated either by “,” or “ “(space). Your task is to find the evaluation result.n
 **
 **  In the input section a single line contains only the expression as a string.
 **
 **
 **
 **  Sample input: 51  600  101 *  +
 **
 **
 **
 **  output:  60651
 **
 **
 **
 **  input: 12, 6, 3, -, /, 2, 1, 5, +, *, +
 **
 **
 **
 **  output: 16
 *
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

/*Postfix evaluation*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLANK ' '

int stack[30];
int top = -1;

void push(int x)
{
    stack[++top] = x; /*push elements into the stack*/
}

int pop()
{
    return stack[top--]; /*pops element from the stack*/
}

/*The driver code*/
int main(void)
{
    char e[50];
    char num[50];
    int g = 0;
    int res = 0, k = 0, e1, op1, op2, temp;
    fgets(e, sizeof(e), stdin); /*taking input*/
    int i = 0;
    while (e[i] != '\0') /*iterating each char*/
    {
        if (g) /*detecting a number*/
        {
            if (e[i] == ' ' || e[i] == ',' || e[i] == '\0') /*checks if there is any space, comma or null character*/
            {
                g = 0;
                temp = atoi(num);
                push(temp);
                k = 0;
                memset(num, 0, 5);
            }
            else
            {
                num[k] = e[i];
                k++;
            }
        }
        else if ((e[i] != BLANK && e[i] != ',' && e[i] != '*' && e[i] != '/' && e[i] != '+' && e[i] && e[i] != '-') || (e[i] == '-' && e[i + 1] != BLANK && e[i + 1] != ',' && e[i + 1] != BLANK && e[i + 1] != '/' && e[i + 1] != '+')) /*if beginning of a number*/
        {
            g = 1;
            k = 0;
            num[k] = e[i];
            k++;
        }
        else if (e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/') /*checks whether any operator is there or not*/
        {
            op2 = pop(); /*popping operators*/
            op1 = pop();
            if (e[i] == '+')
            {
                e1 = op1 + op2;
            }
            else if (e[i] == '-')
            {
                e1 = op1 - op2;
            }
            else if (e[i] == '*')
            {
                e1 = op1 * op2;
            }
            else if (e[i] == '/')
            {
                e1 = op1 / op2;
            }
            push(e1); /*push the result*/
        }
        i++;
    }
    res = pop();         /*popping the last item*/
    printf("\n%d", res); /*printing ans*/
    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// 51  600  101 *  +
//
// 60651

// Test Case 2:-
// 12, 6, 3, -, /, 2, 1, 5, +, *, +
//
// 16

*/