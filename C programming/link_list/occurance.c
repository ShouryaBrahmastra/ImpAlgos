/**
 * @file occurance.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **   A singly linked list and a key is given to you. Your task is to count the number of occurrences of given key in the linked list. In the input section, the first line contains the number of elements followed by the elements of list in the second line separated by spaces. The third line contains the key value for which occurrence has to be calculated.
 **
 **   Expected Time Complexity: O(N)
 **
 **   Constraints:
 **
 **   0 ≤ N ≤ 10^4
 **
 **   Sample input:
 **
 **   7
 **
 **   1 2 1 2 1 3 1
 **
 **   1
 **
 **   output:
 **
 **   4
 *
 * @version 0.1
 * @date 2022-01-12
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

/*C PROGRAM for counting the number of
occurrences of given key in the linked list.
*/
#include <stdio.h>
#include <stdlib.h>

/*declaring node for the link list*/
struct node
{
    int data;
    struct node *next;
} node;

struct node *head;

// Function to create the node of linked list
struct node *create()
{
    struct node *ptr;
    /*entering items of linked list*/
    /*malloc funtion for dynamic initialization*/
    ptr = (struct node *)malloc(sizeof(struct node));
    return ptr;
}

// Function to insert at the end of the linked list
void insert(int item)
{
    struct node *ptr, *temp;
    ptr = create();
    ptr->data = item;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
    }
}

// Functio to check the occurence of the given item
int occurence(int y)
{
    int flag = 0;
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        if (temp->data == y)
        {
            flag++;
        }
        temp = temp->next;
    }
    return flag;
}

/*The driver code*/
int main(void)
{
    int n, data, y, output;

    scanf("%d", &n);
    // Taking input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert(data);
    }
    scanf("%d", &y);
    output = occurence(y);
    // Printing the output
    printf("%d", output);
}
