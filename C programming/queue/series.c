/**
 * @file series.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **   A series of numbers contain only 5's and 7's. Given an integer N, the task is to find Nth number of that series.
 **
 **   Note: Some numbers are 5, 7, 55, 57, 75, 77, 555, 557 ........
 **
 **   Constraints: 1 <= N <= 104
 **
 **   Input: The line of the input contains a single integer N.
 **
 **   Output: Print the Nth number of the specified series
 **
 **
 **
 **   Example:
 **   Input:
 **   5
 **
 **   Output:
 **   75
 *
 * @version 0.1
 * @date 2022-01-12
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>

// The algorithm
int printNthElement(long int n)
{
    int arr[n + 1];
    arr[1] = 5;
    arr[2] = 7;

    for (int i = 3; i <= n; i++)
    {
        if (i % 2 != 0)
            arr[i] = arr[i / 2] * 10 + 5;
        else
            arr[i] = arr[(i / 2) - 1] * 10 + 7;
    }
    return arr[n];
}

// Driver code
int main(void)
{
    long int n;
    scanf("%ld", &n);
    printf("%d", printNthElement(n));
    return 0;
}