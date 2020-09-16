/*
 * Assignment: Homework #2
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description:  C program to print all the prime numbers from a given range (not including start and end values)
 * */

#include <stdio.h>

int main()
{
    int start, end;

    // Get start and end of prime sieve
    printf("Enter the beginning of the prime sieve: ");
    scanf("%d", &start);
    printf("Enter the end of the prime sieve: ");
    scanf("%d", &end);

    // Sieve of Eratosthenes
    char sieve[end];

    // initialize to 0
    for (int i = 0; i < sizeof(sieve); i++)
    {
        sieve[i] = 0;
    }

    sieve[0] = 1;
    sieve[1] = 1;
    for (int i = 2; i * i < end; i++)
    {
        for (int j = i * i; j < end; j += i)
        {
            sieve[j] = 1;
        }
    }

    // Print primes
    printf("Primes: ");
    for (int i = start + 1; i < end; i++)
    {
        if (sieve[i] == 0)
        {
            printf("%d  ", i);
        }
    }

    return 0;
}