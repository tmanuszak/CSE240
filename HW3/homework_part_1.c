/*
 * Assignment: Homework #3
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: File with functions for array initalization, printing arrays, insertion sort, and recursive factorial.
 * */

#include <stdio.h>

/*
Function:  array_initialization
--------------------
Uses  a  for  loop  and  an  if  statement  to  put 5s  in  the  odd
indices of the array and 0s in the even indices.

Parameters:
    int *a: pointer to the int array
    int size: size of the array that a points to

Returns: void
*/
void array_initialization(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            *(a + i) = 0;
        } else
        {
            *(a + i) = 5;
        }
    }
}

/*
Function:  array_printing
--------------------
Uses  a  for  loop  to print the elements of an array

Parameters:
    int *a: pointer to the int array
    int size: size of the array that a points to

Returns: void
*/
void array_printing(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1) 
        {
            printf("%d, ", *(a + i));
        } else
        {
            printf("%d", *(a + i));
        }
    }

    printf("\n");
}

/*
Function:  array_printing
--------------------
Sorts the array that a points to using insertion sort

Parameters:
    int *a: pointer to the int array
    int size: size of the array that a points to

Returns: void
*/
void insertion_sort(int *a, int size)
{
    int value, j;
    for (int i = 0; i < size; i++)
    {
        value = *(a + i);
        j = i - 1;

        while (*(a + j) > value && j >= 0) // Move elements > value to right of value
        {
            *(a + (j + 1)) = *(a + j);
            j -= 1;
        }
        *(a + (j + 1)) = value;
    }
}

/*
Function:  factorial
--------------------
Calculates factorial of a number recursively

Parameters:
    int n: number to calculate n!

Returns: int n
*/
int factorial(int n)
{
    if (n == 0) { // Base case
        return 1;
    } else // Recursive case
    {
        return (n * factorial(n - 1));
    }
}

int main()
{
    int a[] = {2, 5, 7, 9, 12, 13, 15, 17, 19, 20};
    int b[] = {18, 16, 19, -5, 3, 14, 6, 0};
    int c[] = {4, 2, 5, 3, 1};

    /* testing aray_initialization */
    array_printing(a, sizeof(a) / sizeof(a[0])); /* print: 2, 5, 7, 9, 12, 13, 15, 17, 19, 20 */
    array_initialization(a, sizeof(a) / sizeof(a[0]));
    array_printing(a, sizeof(a) / sizeof(a[0])); /* print: 5, 0, 5, 0, 5, 0, 5, 0, 5, 0 */

    /* testing insertionSort */
    array_printing(b, sizeof(b) / sizeof(b[0])); /* print: 18, 16, 19, -5, 3, 14, 6, 0 */
    insertion_sort(b, sizeof(b) / sizeof(b[0]));
    array_printing(b, sizeof(b) / sizeof(b[0])); /* print: -5, 0, 3, 6, 14, 16, 18, 19 */

    /* testing factorial */
    printf("%d\n", factorial(5)); /* print: 120 */

    c[0] = factorial(c[0]);
    c[1] = factorial(c[2]);
    array_printing(c, sizeof(c) / sizeof(c[0])); /* print: 24, 120, 5, 3, 1 */

    return 0;
}



