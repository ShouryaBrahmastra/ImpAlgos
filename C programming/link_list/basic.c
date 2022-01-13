/**
 * @file basic.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **   Consider the following functions in your C program to apply the insert, delete and display nodes in a Single Linked List.
 **
 **   create(): to create a node for the list
 **
 **   insert_end(): to insert a node at the end of the list
 **
 **   insert_position(): to insert a node at a specified position in the list
 **
 **   delete_end(): to delete a node from the end of the list
 **
 **   display(): to display the list
 **
 **   Write a menu-driven program in C to create (apply(create() function and call within insert function) and insert nodes in a singly linked list one after another (apply insert_end()). Then insert a node at a specific position (apply insert_position()) from the list. Now delete nodes from the end of the list (apply delete_end()). You can display the list anytime after inserting and/or deleting the elements (apply display()).
 **
 **
 **    Five types of queries are given below:
 **
 **    1 means  insert at end
 **
 **    2 means insert at a specified position
 **
 **    3 means display
 **
 **    4 means delete from last
 **    **
 **    5 means exit
 **
 **    The input section shows the type of queries.
 **    The output section displays the status of the queries.
 **
 **   Example 1:
 **
 **   input=
 **
 **   1  10
 **
 **   1  20
 **
 **   1  40
 **
 **   2  2  30             //2=choice, 2=position starting from index 0, 30=element to be inserted
 **
 **   3
 **
 **   4
 **
 **   4
 **
 **   3
 **
 **   5
 **
 **   output=
 **
 **   10  20  30  40
 **
 **   10  20
 *
 * @version 0.1
 * @date 2022-01-12
 *
 * @copyright Copyright (c) 2022
 *
 */

//  Solution

#include <stdio.h>
#include <stdlib.h>

/*Declaring the stucture for a node initialization*/
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *headAddress = NULL;

/*Function used to display the Single Link List*/
void display()
{
    if (headAddress == NULL)
    {
        printf("Empty list\n");
        return;
    }
    Node *init = headAddress;
    while (init->next != NULL)
    {
        printf("%d ", init->data);
        init = init->next;
    }
    printf("%d\n", init->data);
}

/*Function used to create the data of the Single Link List*/
Node *create(int data)
{
    /*Allocating a new memory of the node for creation*/
    Node *address = (Node *)malloc(sizeof(Node));
    address->data = data;
    address->next = NULL;
    return address;
}

/*Function used to insert the element from the end of the List*/
void insertEnd(int data)
{
    if (headAddress == NULL) /*if linked list empty*/
    {
        headAddress = create(data); /*calling create function*/
        return;
    }
    Node *init = headAddress;
    while (init->next != NULL) /*we will travere to the last*/
    {
        init = init->next;
    }
    /*calling create function for insertion of new data in the new node*/
    Node *newNode = create(data);
    /*this is the last node that is inserted*/
    init->next = newNode;
}

/*deletion from last*/
void deleteEnd()
{
    if (headAddress == NULL)
    {
        /*if linked list empty*/
        printf("Empty list\n");
        return;
    }
    /*if only one node is there*/
    if (headAddress->next == NULL)
    {
        headAddress = NULL;
        return;
    }

    Node *init = headAddress;

    /*traversing to the last node*/
    while (init->next->next != NULL)
    {
        init = init->next;
    }
    init->next = NULL;
}

/*Function for Insertion at a specific position in a link list*/
void insertPosition(int num, int data)
{
    /*if the position to be inserted at is zero*/
    if (num == 0)
    {
        /*if linked list empty*/
        if (headAddress == NULL)
        {
            /*calling create function*/
            headAddress = create(data);
            return;
        }
        Node *temp = headAddress;
        /*calling create function*/
        headAddress = create(data);
        headAddress->next = temp;
        return;
    }
    int count = 0;
    Node *init = headAddress;
    /*going to that specified position*/
    while (count != num - 1)
    {
        init = init->next;
        count++;
    }
    /*the insertion at specific position is done here basically */
    Node *temp = init->next;
    Node *newNode = create(data);
    newNode->data = data;
    newNode->next = temp;
    init->next = newNode;
}

/*The driver code*/
int main(void)
{
    int cont = 1;
    while (cont)
    {
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            scanf("%d", &data);
            insertEnd(data);
            break;
        }

        case 2:
        {
            int data, num;
            scanf("%d", &num);  /*entering position  to be inserted*/
            scanf("%d", &data); /*entering item to be inserted*/
            insertPosition(num, data);
            break;
        }

        case 3:
        {
            display();
            break;
        }

        case 4:
        {
            deleteEnd();
            break;
        }

        case 5:
        {
            cont = 0;
            break;
        }

        default:
            /*for incorrect choice*/
            printf("Incorrect Choice\n");
            break;
        }
    }
    return (0);
}