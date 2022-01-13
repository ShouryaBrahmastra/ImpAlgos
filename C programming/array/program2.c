/**
**  Given a list of size N and an integer M. Find if there's a triplet in the array which sums up to the given integer M.
**
**
**  Time Complexity: O(N2)
**  Auxiliary Space: O(1)
**
**  Example Input:
**
**  N = 6, M = 13
**
**  a[] = [1 4 45 6 10 8]
**
**  Output:
**
**  1
**
**  Explanation: The triplet {1, 4, 8} in the array sums up to 13.
**/

// Solution

/**
 * @file program2.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

void output(int a[50], int n, int m)
{
    int i, j, c = 0, k;

    /*Algorithm*/
    for (i = 0; i < n - 2; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                if (((a[i]) + (a[j]) + (a[k]) == m))
                    c++;
            }
        }
    }

    printf("%d\n", c);
}

/*Driver code*/
int main(void)
{
    int n, i, m, *a, c = 0;

    scanf("%d %d", &n, &m);

    /*Dynamic allocation*/
    a = (int *)malloc(n * sizeof(int));

    /*Taking the array inputs*/
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    /*Output Code*/
    output(a, n, m);

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// 6 13
// 1 4 45 6 10 8
// 1

*/