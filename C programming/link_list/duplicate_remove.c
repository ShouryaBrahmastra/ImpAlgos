/**
 * @file duplicate_remove.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Given an unsorted linked list of N nodes. The task is to remove duplicate elements
 **  from this unsorted Linked List. When a value appears in multiple nodes, the node
 **  which appeared first should be kept, all other duplicates are to be removed.
 **
 **  In the input section, the first line contains the number of elements followed by
 **  the elements in the second line separated by spaces.
 **
 **  Expected Time Complexity: O(N)
 **
 **  Constraints:
 **  1 <= size of linked lists <= 106
 **  0 <= numbers in list <= 104
 **
 **   Sample Input: 4 5 2 2 4
 **   Output: 5 2 4
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

/* structure of the node */
struct node
{
    int input;
    struct node *next;
};

/*function for deleting duplicate nodes*/
void Duplicate_node(struct node *q)
{
    struct node *present = q, *index = NULL, *temp = NULL;

    if (q == NULL)
    {
        return;
    }
    else
    {
        while (present != NULL)
        {
            temp = present;
            index = present->next;

            while (index != NULL)
            {
                if (present->input == index->input)
                {
                    temp->next = index->next;
                }
                else
                {
                    temp = index;
                }
                index = index->next;
            }
            present = present->next;
        }
    }
}

/*inserting at end*/
void insert_end(struct node **q, int data)
{
    struct node *temp, *r;
    temp = *q;
    if (*q == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->input = data;
        temp->next = NULL;
        *q = temp;
    }
    else
    {
        temp = *q;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        r = (struct node *)malloc(sizeof(struct node));
        r->input = data;
        r->next = NULL;
        temp->next = r;
    }
}

/*function for displaying the list*/
void display(struct node *q)
{
    while (q != NULL)
    {
        printf("%d ", q->input);
        q = q->next;
    }
}

/*The driver code */
int main(void)
{
    struct node *p = NULL;

    int n, data;
    /*Taking the size of the list*/
    scanf("%d", &n);

    /*Taking the list elements from the user*/
    for (int i = 1; i <= n; i++)
    {
        int temp = scanf("%d", &data);
        insert_end(&p, data);
    }
    /*Calling the function to remove the duplicate node elements*/
    Duplicate_node(p);

    display(p);

    return 0;
}