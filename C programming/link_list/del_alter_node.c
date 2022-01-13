/**
 * @file del_alter_node.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  A Singly Linked List of size N is given to you. Your task is to delete all alternate nodes of the
 **  list. The input section where the first line contains the number of elements followed by the
 **  elements in the second line separated by spaces.
 **
 **  Expected Time Complexity: O(N).
 **
 **  Constraints:
 **
 **  1<= N <=100
 **
 **  Sample input
 **
 **  6
 **
 **  1 2 3 4 5 6
 **
 **  output:
 **
 **  1 3 5
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

/*function to delete alternate nodes*/
void Alternate_delete(struct node *q)
{
    if (q == NULL)
        return;

    struct node *prev = q;
    struct node *node = q->next;

    while ((prev != NULL) && (node != NULL))
    {
        prev->next = node->next;
        free(node);

        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}

/*inserting at end*/
void end_inserting(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;
    if (*q == NULL)
    {
        /*Dynamic memory allocation*/
        temp = (struct node *)malloc(sizeof(struct node));
        /*Inserting logic*/
        temp->input = num;
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

        /*Dynamic memory allocation*/
        r = (struct node *)malloc(sizeof(struct node));

        r->input = num;
        r->next = NULL;
        temp->next = r;
    }
}

/*Function showing the list*/
void show(struct node *q)
{
    while (q != NULL)
    {
        printf("%d ", q->input);
        q = q->next;
    }
}

/* Driver Code */
int main(void)
{
    struct node *p = NULL;

    int n, num;

    /*Taking the size of the list*/
    scanf("%d", &n);

    /*The list elements from the user*/
    for (int i = 1; i <= n; i++)
    {
        int temp = scanf("%d", &num);
        end_inserting(&p, num);
    }

    /*Calling the alternate delete function*/
    Alternate_delete(p);

    show(p);

    return 0;
}