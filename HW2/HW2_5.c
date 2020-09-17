/*
 * Assignment: Homework #2
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: C program to multiply two arrays of size n defined as (arr3)[i] = arr1[(n-1)-i] * arr2[i]
 * */

#include <stdio.h>

int main()
{
    int arrayLength;

    // Get array length from user
    printf("Enter the length of the arrays: ");
    scanf("%d", &arrayLength);
    while (arrayLength < 0)
    {
        printf("Array length must be non-negative.\nEnter the length of the arrays: ");
        scanf("%d", &arrayLength);
    }
    // Initialize arrays
    int arr1[arrayLength], arr2[arrayLength];
    long int arr3[arrayLength];

    // Fill arrays from user
    for (int i = 0; i < arrayLength; i++)
    {
        printf("Enter element %d of array1: ", (i + 1));
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < arrayLength; i++)
    {
        printf("Enter element %d of array2: ", (i + 1));
        scanf("%d", &arr2[i]);
    }

    // Calculate arr3
    for (int i = 0; i < arrayLength; i++)
    {
        arr3[i] = arr2[i] * arr1[arrayLength - 1 - i];
    }

    // Print arr3
    printf("array3 contains: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%ld ", arr3[i]);
    }
}