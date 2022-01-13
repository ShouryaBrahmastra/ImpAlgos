/**
 * @file stack1.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 *
 * @brief
 *
 **  Write a program in c that will reverse a string using stack as an auxiliary data structure.
 **
 **  Input: A line of text.
 **  Output: A line of text.
 **
 **  Example:
 **  Input : abcd xyz
 **
 **  Output: zyx dcba
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
#include <stdlib.h>
#include <limits.h>

/*Stack representation*/
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

/*function to create a stack of given capacity which
 *initializes size of stack as 0
 */
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

/*Stack is full when top is equal to the last index*/
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

/*Stack is empty when top is equal to -1*/
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

/*Function to add a word to stack which is increased top by 1*/
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

/*Function to remove an item from stack which decreases top by 1*/
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->array[stack->top--];
}

/*reversing a string*/
void reverse(char str[])
{
    int n = strlen(str);
    struct Stack *stack = createStack(n);

    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);

    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

/*Main driver  program*/
int main(void)
{
    char str[50];

    /*Taking the string from the user*/
    scanf("%[^\n]s", str);

    reverse(str);

    printf("%s", str);
    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// abcd xyz
// zyx dcba

*/