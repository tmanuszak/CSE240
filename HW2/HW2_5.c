/*
 * Assignment: Homework #2
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: C program to multiply two arrays of size n defined as (arr1*arr2)[i] = arr1[(n-1)-i] * arr2[i]
 * */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>     // Used for SHRT_MAX
#define ARRAY_LENGTH 10 // change as desired

int main()
{

    int arr1[ARRAY_LENGTH], arr2[ARRAY_LENGTH];
    long int arr3[ARRAY_LENGTH];

    // initialize arrays with random integers
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        arr1[i] = rand() % SHRT_MAX;
    }
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        arr2[i] = rand() % SHRT_MAX;
    }

    // Calculate arr3
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        arr3[i] = arr2[i] * arr1[ARRAY_LENGTH - 1 - i];
    }

    // Print arr3
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%ld ", arr3[i]);
    }
}