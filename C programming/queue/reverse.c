/**
 * @file reverse.c
 * @author Shourya Gupta (https://github.com/ShouryaBrahmastra)
 * @brief
 *
 **  You are given an integer K and a queue of integers. You have to reverse the order of the first K elements of the queue,
 **  leaving the other elements in the same relative order.
 **  Only following standard operations are allowed on queue.
 **              enqueue(x): Add an item x to rear of queue
 **              dequeue (): Remove an item from front of queue
 **  size (): Returns number of elements in queue.
 **              front (): Finds front item.
 **  In the input section, the first line contains the number of elements followed by value of k. The second line
 **  contains the elements of queue separated by spaces.
 **  Expected Time Complexity : O(n)
 **  Constraints:
 **  1 <= N <= 1000
 **  1 <= K <= N
 **  Sample input:
 **  5 3
 **  1 2 3 4 5
 **  Output
 **  3 2 1 4 5
 *
 * @version 0.1
 * @date 2022-01-12
 *
 * @copyright Copyright (c) 2022
 *
 */

// Solution

#include <stdio.h>

/*global variables*/
int front = -1;
int rear = -1;
int array[50];
int size = 50;
int stack[50];
int top = -1;

/*stack operations*/
void Push(int data)
{
    if (top + 1 > size)
    {
        printf("Stack Overflow!");
    }
    else
    {
        stack[top + 1] = data;
        top++;
    }
}

void Pop()
{
    if (top - 1 > -1)
    {
        top--;
    }
}

int Peek()
{
    return stack[top];
}

/*queue operations*/
void Dequeue()
{
    if (front > rear)
    {
        front = -1;
        rear = -1;
        printf("Queue is empty");
    }
    else
    {
        front++;
    }
}

/*Front declaration*/
int Front()
{
    return array[front];
}

/*Enqueue the inputed queue */
void Enqueue(int data)
{
    if (rear == size - 1)
    {
        printf("queue overflow");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        array[rear] = data;
    }
    else
    {
        rear++;
        array[rear] = data;
    }
}

/*The driver code*/
int main(void)
{
    int size = 50;
    int len, lim, temp;
    scanf("%d", &len);
    scanf("%d", &lim);
    if (lim > len)
    {
        printf("INVALID INPUT");
        return 0;
    }

    /*filling the queue*/
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &temp);
        Enqueue(temp);
    }

    /*pushing the first j items to stack*/
    for (int j = front; j < lim; j++)
    {
        int temp1 = Front(array, &front, &rear);
        temp1 = Front();
        Dequeue();
        Push(temp1);
    }

    /*reversing the items*/
    for (int k = 0; k < lim; k++)
    {
        int temp2 = Peek();
        printf("%d ", temp2);
        Pop();
    }

    /*printing the rest items*/
    for (int l = front; l <= rear; l++)
    {
        int temp3 = Front();
        Dequeue();
        printf("%d ", temp3);
    }
}