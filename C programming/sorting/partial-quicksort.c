/**
 * @file partial-quicksort.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot
 **  and partitions the given array around the picked pivot. Pick the first element
 **  as pivot.
 **
 **  The key process in quickSort is partition(). Target of partitions is, given an
 **  array and an element x of array as pivot, put x at its correct position in sorted
 **  array and put all smaller elements (smaller than x) before x, and put all greater
 **  elements (greater than x) after x. All this should be done in linear time complexity.
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
 **
 **  Partially sorted array after m pass.
 **
 **  Example:
 **
 **  Input :
 **  6
 **  27 10 36 18 25 45
 **  5
 **  Output :
 **  10 18 25 27 36 45
 *
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>

void print_arr(int a[], int n);
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int c = 0;
int partition(int a[], int lb, int ub, int m, int n)
{
    int pivot, start, end;
    if (lb < ub)
    {
        pivot = a[lb];
        start = lb;
        end = ub;
        while (start < end)
        {
            while (a[start] <= pivot)
            {
                start++;
            }
            while (a[end] > pivot)
            {
                end--;
            }
            if (start < end)
            {
                swap(&a[start], &a[end]);
            }
        }
        swap(&a[lb], &a[end]);

        c = c + 1;

        if (c == m)
        {
            print_arr(a, n);
        }
    }
    return end;
}

void quicksort(int a[], int lb, int ub, int m, int n)
{
    if (lb < ub)
    {
        int l = partition(a, lb, ub, m, n);
        quicksort(a, lb, l - 1, m, n);
        quicksort(a, l + 1, ub, m, n);
    }
}

void print_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Driver program
int main(void)
{
    int arr[1000], n, m;
    // Taking the size of the array
    scanf("%d", &n);

    // Array elements according to the user wish
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    quicksort(arr, 0, n - 1, m, n);

    print_arr(arr, n);
    return 0;
}