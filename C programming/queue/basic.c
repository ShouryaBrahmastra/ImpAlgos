/**
 * @file basic.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 ** Write a menu driven program in C to implement the basic Queue operations
 ** [ menu options are PUSH, POP, DISPLAY, EXIT ] using ADT [ abstract data type ].
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
#define MAX 100

/* Declaring the array */
struct Queue
{
    int array[MAX];
    int front;
    int rear;
};

void insert(struct Queue *address, int data) /*insertion of the data to the structure's queue*/
{
    if ((address->front == 0 && address->rear == MAX - 1) ||
        (address->rear == (address->front - 1) % (MAX - 1)))
    {
        printf("\nQUEUE FULL");
        return;
    }

    else if (address->front == -1) /* Insert First Element */
    {
        address->front = address->rear = 0;
        address->array[address->rear] = data;
    }

    else if (address->rear == MAX - 1 && address->front != 0)
    {
        address->rear = 0;
        address->array[address->rear] = data;
    }

    else
    {
        address->rear++;
        address->array[address->rear] = data;
    }
}

int delete (struct Queue *address) /*deletion of the data from the structure's queue*/
{
    if (address->front == -1)
    {
        printf("EMPTY QUEUE\n");
        return 0;
    }
    int data = address->array[address->front];
    address->array[address->front] = -1;
    if (address->front == address->rear)
    {
        address->front = -1;
        address->rear = -1;
    }
    else if (address->front == MAX - 1)
        address->front = 0;
    else
        address->front++;

    return data;
}

void display(struct Queue *address) /*deleting the item from the structure's queue*/
{
    int f = address->front;
    int r = address->rear;
    if (f == -1)
    {
        printf("\nEMPTY QUEUE");
        return;
    }
    if (f <= r)
    {
        while (f <= r)
        {
            printf("%d ", address->array[f]);
            f++;
        }
    }
    else
    {
        while (f <= MAX - 1)
        {
            printf("%d ", address->array[f]);
            f++;
        }
        f = 0;
        while (f <= r)
        {
            printf("%d ", address->array[f]);
            f++;
        }
    }
}

/* The main driver code */
int main(void)
{
    int cont = 1, choice, data;

    struct Queue q1 = {.front = -1, .rear = -1};
    /* Dynamic */
    struct Queue *address = (struct Queue *)malloc(sizeof(q1));
    *address = q1;

    printf("Menu driven queue program : ");
    while (cont) /*main loop*/
    {
        printf("\n1.>Push\n2.>Pop\n3.>Display\n4.>Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: /* PUSH */
            printf("Enter the element to be pushed: \n");
            scanf("%d", &data);
            insert(address, data);
            break;
        case 2: /* POP */
            data = delete (address);
            if (data != 0)
                printf("The element deleted from the queue is: %d\n", data);
            break;
        case 3:
            printf("The element in the queue is: ");
            display(address);
            printf("\n");
            break;
        case 4: /*exiting*/
            cont = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}