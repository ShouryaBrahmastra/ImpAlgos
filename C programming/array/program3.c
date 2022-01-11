/**
**  Given an array of N non-negative integers – where each element in the array is number of blocks in a pillar.
**  Assume height and width of each block is 1, calculate how much rain water can be accumulated between the pillars.
**
**  Time Complexity: O(N)
**
**  Auxiliary Space: O(N)
**
**  Example 1:
**
**  Input: N = 6
**
**  a[] = {3,0,0,2,0,4}
**
**  Output: 10
**
**
**  Example 2:
**
**  Input: N = 3
**
**  arr[] = {6,9,9}
**
**  Output: 0
**
**  [ Explanation: No water will be trapped. ]
**/

// Solution

/**
 * @file program3.c
 * @author Shourya Gupta
 * @version 0.1
 * @date 2022-01-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int trap(int *height, int heightSize)
{
    int *max_heights_l2r = calloc(heightSize, sizeof(int));
    int *max_heights_r2l = calloc(heightSize, sizeof(int));
    int i, water = 0;

    if (heightSize == 0)
        return 0;

    max_heights_l2r[0] = height[0];
    for (i = 1; i < heightSize; i++)
    {
        max_heights_l2r[i] = MAX(max_heights_l2r[i - 1], height[i]);
    }

    max_heights_r2l[heightSize - 1] = height[heightSize - 1];
    for (i = heightSize - 2; i >= 0; i--)
    {
        max_heights_r2l[i] = MAX(max_heights_r2l[i + 1], height[i]);
    }

    for (i = 1; i < heightSize - 1; i++)
    {
        int curr_h = MIN(max_heights_l2r[i - 1], max_heights_r2l[i + 1]) - height[i];
        if (curr_h > 0)
            water += curr_h;
    }

    free(max_heights_l2r);
    free(max_heights_r2l);
    return water;
}

int main(void)
{
    int heights[10], n, i;

    /*Taking the size of the array*/
    scanf("%d", &n);

    /*Taking the array of the pillar*/
    for (i = 0; i < n; i++)
        scanf("%d", &heights[i]);

    /*The maximum amount of water that can be trapped is */
    printf("%d", trap((heights), (n)));

    return 0;
}

/*

// Output screen:-

// Test Case 1:-
// 3
// 2 0 2
// 2

*/