/**
 * @file balanced_bst.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Write a program in C that will check if a BST is Balanced or not.
 **
 **  Consider a balancing scheme where following conditions should be checked to determine if a BST is balanced.
 **  An empty BST is balanced. A non-empty BST T is balanced if:
 **  1) Left subtree of T is balanced
 **  2) Right subtree of T is balanced
 **  3) The difference between sum of keys of left subtree and right subtree is not more than 10.
 **
 **  Input :
 **
 **  line 1: Size of the data set (N)
 **
 **  line 2: N number of integers
 **
 **  Output: Balanced/Unbalanced
 **
 **  Example1 :
 **
 **  Input :
 **
 **  3
 **
 **  10 3 15
 **
 **  Output: Unbalanced
 **
 **
 **  Example2 :
 **
 **  Input :
 **
 **  7
 **
 **  10 3 15 1 7 14 20
 **
 **  Output: Unbalanced
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
#include <math.h>

// Node structure
struct Node
{
    int counter;
    struct Node *left, *right;
};

int sum(struct Node *Node) // returns the sum of the counters of the subtree
{
    if (Node == NULL)
        return 0;

    return sum(Node->left) + Node->counter + sum(Node->right);
}

// checks the key of the tree that if the tree is balanced
int checker(struct Node *Node)
{

    if (Node == NULL)
        return 1;

    // Calculates the sum of left and right sub trees
    int l = sum(Node->left);
    int r = sum(Node->right);

    // to return absolute value of left-right
    if (abs(l - r) <= 10 && checker(Node->left) && checker(Node->right))
        return 1;

    return 0;
}

// Function to create a new node in the tree
struct Node *newNode(int item)
{
    // Dynamic memory allocation
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->counter = item;
    tmp->left = tmp->right = NULL;

    return tmp;
}

// adding a Node in the tree
struct Node *adding(struct Node *Node, int counter)
{
    if (Node == NULL)
        return newNode(counter);

    if (counter < Node->counter)
        Node->left = adding(Node->left, counter);
    else if (counter > Node->counter)
        Node->right = adding(Node->right, counter);
    return Node;
}

// Driver Code
int main(void)
{
    struct Node *root = NULL;

    int n, i, counter;

    // taking the Size of the data set from the user
    scanf("%d", &n);
    // Taking the first input as the root
    scanf("%d", &counter);
    root = adding(root, counter);

    // N number of integers given by the user
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &counter);
        adding(root, counter);
    }

    if (checker(root))
        printf("Balanced");
    else
        printf("Unbalanced");

    return 0;
}