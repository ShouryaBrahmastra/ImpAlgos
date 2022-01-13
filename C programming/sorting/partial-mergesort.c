/**
 * @file partial-mergesort.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Merge Sort divides the input array into two halves, calls itself for the
 **  two halves, and then merges the two sorted halves. The merge() function is
 **  used for merging two halves. The merge(arr, l, m, r) is a key process that
 **  assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted
 **  sub-arrays into one.
 **
 **  Write a program to arrange a set of integers using Merge sort: Algorithm.
 **
 **  Input:
 **
 **  Line1: no of elements
 **
 **  Line2: array elements
 **
 **  Line3: no of pass to complete (m)
 **
 **
 **  Output:
 **
 **  Partially sorted array after m pass.
 **
 **  input :
 **  8
 **  11 77 33 22 88 55 44 66
 **  3
 **  output :
 **  11 22 33 44 55 66 77 88
 *
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>

int main(void)
{
    int x, y, z, u, v, size, a1, b1, a2, b2, a[100], t[100];
    int c = 0;

    scanf("%d", &v);

    for (x = 0; x < v; x++)
    {

        scanf("%d", &a[x]);
    }

    scanf("%d", &u);

    if (u == 0)
    {
        for (int t = 0; t < v; t++)
            printf("%d ", a[t]);
        printf("\n");
    }

    for (size = 1; size < v; size = size * 2)
    {

        a1 = 0;
        z = 0;
        while (a1 + size < v)
        {
            b1 = a1 + size - 1;
            a2 = b1 + 1;
            b2 = a2 + size - 1;
            if (b2 >= v)
                b2 = v - 1;

            x = a1;
            y = a2;

            while (x <= b1 && y <= b2)
            {
                if (a[x] <= a[y])
                    t[z++] = a[x++];
                else
                    t[z++] = a[y++];
            }

            while (x <= b1)
                t[z++] = a[x++];
            while (y <= b2)
                t[z++] = a[y++];

            a1 = b2 + 1;
        }

        for (x = a1; z < v; x++)
            t[z++] = a[x];

        for (x = 0; x < v; x++)
            a[x] = t[x];

        c = c + 1;
        if (c == u && c > 0)
        {
            for (int t = 0; t < v; t++)
                printf("%d ", a[t]);
            printf("\n");
        }
    }

    return 0;
}