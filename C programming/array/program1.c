/**
**  Given an array of size N and an integer M where M is smaller than size of array, find the Mth smallest and largest element
**  in the array. All array elements are distinct.
**
**  Time Complexity: O(N)
**
**  Additional Space: O(1)
**
**  Constraints:
**
**  1 <= N <= 105
**
**  1 <= array[i] <= 105
**
**  1 <= M <= N
**  Input:
**
**  1st line – N
**
**  2nd line array elements
**
**  3rd line – M
**
**  Output:
**
**  1st line – the smallest element
**
**  2nd line – the largest element
**/

// Solution

/**
 * @file program1.c
 * @author Shourya Gupta
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

int output(int a[100], int n, int m)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\n%d\n", a[m - 1]); // the smallest element
    printf("\n%d\n", a[n - m]); // the largest element
}

int main(void)
{
    int *a, i, j, n, m, temp;
    /*For entering the number of elements in the first line*/
    scanf("%d", &n);

    /*Dynamic allocation*/
    a = (int *)malloc(n * sizeof(int));

    /*For taking the inputs of the array*/
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    /*For taking the value of M from the user*/
    scanf("%d", &m);

    output(a, n, m);

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// 4
// 1 4 5 7
// 3

// 4

// 5

*/