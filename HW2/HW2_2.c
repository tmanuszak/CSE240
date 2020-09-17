/*
 * Assignment: Homework #2
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description:  C program to display multiplication table for a given number. 
 * Accept the number from the user. (Multiplication from InputNumber*1 to InputNumber *10)
 * */

#include <stdio.h>

int main()
{
    int inputNumber;
    int table[10];

    // Get inputNumber
    printf("Enter a number: ");
    scanf("%d", &inputNumber);

    // Generate multiplication table
    for (int i = 0; i < 10; i++)
    {
        table[i] = inputNumber * (i + 1);
    }

    // Print table 
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", table[i]);
    }

    return 0;
}
