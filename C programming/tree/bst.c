/**
 * @file bst.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Write a program in C that will create a Binary Search Tree with the given
 **  set of integers and after creation it will traverse the BST / search a key
 **  from the BST,
 **  in menu driven fashion [ 1-> Preorder , 2-> Inorder , 3-> Postorder,  4-> Search, 5->Exit ]
 **
 **  Input :
 **
 **  line 1: Size of the data set (N)
 **
 **  line 2: N number of integers
 **
 **  line 3: Choice
 **
 **  Output: According to the given choice
 **
 **  Example1 :
 **
 **  Input :
 **
 **  9
 **
 **  45 22 77 11 30 90 15 25 88
 **
 **  2
 **
 **  5
 **
 **  Output:
 **  11 15 22 25 30 45 77 88 90
 **
 **
 **  Example2 :
 **
 **  Input :
 **
 **  9
 **
 **  45 22 77 11 30 90 15 25 88
 **
 **  4
 **
 **  15
 **
 **  5
 **
 **  Output:
 **  Found
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

// Declaring a structure
typedef struct node
{
    int data;
    struct node *left, *right;
} node;

// Global declaration
node *initial = NULL;

// Creating a function
void Create(int data)
{
    node *a, *b = initial;

    a = (node *)malloc(sizeof(node));
    a->data = data;
    a->left = NULL;
    a->right = NULL;

    if (initial == NULL)
        initial = a;

    else
    {
        while (b != NULL)
        {
            if ((a->data) < (b->data))
            {
                if (b->left == NULL)
                {
                    b->left = a;
                    b = NULL;
                }
                else
                {
                    b = b->left;
                }
            }
            else
            {
                if (b->right == NULL)
                {
                    b->right = a;
                    b = NULL;
                }
                else
                {
                    b = b->right;
                }
            }
        }
    }
}

// Before the order
void order(node *initial)
{
    if (initial != NULL)
    {
        printf("%d ", initial->data);
        order(initial->left);
        order(initial->right);
    }
}

// With the order
void With_order(node *initial)
{
    if (initial != NULL)
    {
        With_order(initial->left);
        printf("%d ", initial->data);
        With_order(initial->right);
    }
}

// After the order
void After_order(node *initial)
{
    if (initial != NULL)
    {
        After_order(initial->left);
        After_order(initial->right);
        printf("%d ", initial->data);
    }
}

node *find(int data)
{
    node *a, *b = NULL, *par;
    a = initial;
    while ((a != NULL) && (data != a->data))
    {
        if (data < a->data)
        {
            b = a;
            a = a->left;
        }
        else
        {
            b = a;
            a = a->right;
        }
    }
    par = b;
    if (a == NULL)
        printf("Not Found");
    else
        printf("Found");
}

// Driver code
void main(void)

{
    int N;
    int data, ch, i, n;

    scanf("%d", &N);

    // Array data that is user defined
    for (i = 0; i < N; i++)
    {
        scanf("%d", &data);
        Create(data);
    }

    while (1)

    {
        // Choosing the order of the tree
        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
            order(initial);
            break;

        case 2:
            With_order(initial);
            break;

        case 3:
            After_order(initial);
            break;

        case 4:
            scanf("%d", &data);
            initial = find(data);
            break;

        case 5:
            exit(0);

        default:
            printf("\nWrong option");
            break;
        }
    }
}