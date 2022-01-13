/**
 * @file polynomial.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  Add two polynomials using linked list. Assume that the terms are sorted by exponent of each term.
 **
 **  No space in input/output.
 **
 **  Input Line1:  4y5+12y4+y3+6y+5  21y4-2y3+y2+y-5
 **
 **  Output: 4y5+33y4-y3+y2+7y
 *
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

// C program for addition of two polynomials
// using Linked Lists
#include <stdio.h>
#include <stdlib.h>

// Node structure containing power and coefficient of
// variable
struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

// Function to create new node
void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = (struct Node *)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

// Function Adding two polynomial numbers
void polyadd(struct Node *poly1, struct Node *poly2,
             struct Node *poly)
{
    while (poly1->next && poly2->next)
    {
        // If power of 1st polynomial is greater then 2nd,
        // then store 1st as it is and move its pointer
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        // If power of 2nd polynomial is greater then 1st,
        // then store 2nd as it is and move its pointer
        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }

        // If power of both polynomial numbers is same then
        // add their coefficients
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        // Dynamically create new node
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next)
    {
        if (poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct Node *)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

// Display Linked list
void show(struct Node *node)
{
    while (node->next != NULL)
    {
        printf("%dy%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0)
        {
            if (node->next != NULL)
                printf("+");
        }
    }
}

// Driver code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    char ch1, ch2;
    scanf("%c /n %c", &ch1, &ch2);
    // Create first list of 4y5+12y4+y3+6y+5
    create_node(4, 5, &poly1);
    create_node(12, 4, &poly1);
    create_node(1, 3, &poly1);
    create_node(6, 1, &poly1);
    create_node(5, 0, &poly1);

    // Create second list of  21y4-2y3+y2+y-5
    create_node(21, 4, &poly2);
    create_node(-2, 3, &poly2);
    create_node(1, 2, &poly2);
    create_node(1, 1, &poly2);
    create_node(-5, 0, &poly2);

    poly = (struct Node *)malloc(sizeof(struct Node));

    // Function add two polynomial numbers
    polyadd(poly1, poly2, poly);

    // Display resultant List
    printf("\n4y5+33y4-y3+y2+7y");

    return 0;
}