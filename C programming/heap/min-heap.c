/**
 * @file min-heap.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Write a C program that will create a Min-heap from an input array and print it in level order.
 **  Input:
 **  Line 1: Size of the array
 **  Line 2:  Array elements.
 **
 **  Output:
 **  Line 1: Print the min-heap in level order
 **  Line 2: No of swap required to create the min-heap.
 **
 **  Example:
 **  Input:
 **  7
 **  5 8 4 7 2 6 3
 **  Output:
 **  2 5 3 7 8 6 4
 **  3
 *
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>
#include <stdlib.h>

int c = 0; // Swap counter

// perform Swapping of elements
void Swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

void Heapsort(int array_number[], int n, int i)
{

    int smallest = i; // initialize smallest as root

    // left = (2*i) + 1
    int left = (2 * i) + 1;
    // right = (2*i) + 2
    int right = (2 * i) + 2;

    // if left child is smaller than root
    if (left < n && array_number[left] < array_number[smallest])
        smallest = left;

    // if right child is smaller than smallest so far
    if (right < n && array_number[right] < array_number[smallest])
        smallest = right;

    // if smallest is not root
    if (smallest != i)
    {
        Swap(&array_number[i], &array_number[smallest]);
        c++;
        // recursively Heapsort the affected sub-tree
        Heapsort(array_number, n, smallest);
    }
}

// build a min-Heap from the given array_numberay
void Build_heap(int array_number[], int n)
{
    int i;
    // index of last non-leaf node
    int start = (n / 2) - 1;

    // perform reverse level order traversal from last non-leaf node and Heapsort each node
    for (i = start; i >= 0; i--)
        Heapsort(array_number, n, i);
}

// to print the Heap
void printHeap(int array_number[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", array_number[i]);
    printf("\n");
}

// main driver code
int main(void)
{

    int i, n, *array_number;

    scanf("%d", &n);
    array_number = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &array_number[i]);

    Build_heap(array_number, n);

    printHeap(array_number, n);
    printf("%d\n", c);

    return 0;
}