/*
 * Assignment: Homework #2
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description:  C program to calculate Simple Interest and Total Amount (Interest + Principal
Amount). Accept Principal Amount, Rate of Interest and Duration from the user.
 * */

#include <stdio.h>
#include <math.h>

int main()
{
    float simpleInterest, total, interestRate, principalAmount;
    int duration;

    // Get principalAmount
    printf("Enter the principal amount: ");
    scanf("%f", &principalAmount);

    //Get interestRate
    printf("Enter the rate of interest (as a percent): ");
    scanf("%f", &interestRate);

    //Get duration
    printf("Enter the duration (time in years): ");
    scanf("%d", &duration);

    // Calculate simpleInterest
    simpleInterest = principalAmount * (interestRate / 100) * duration;

    // Calculate total
    total = principalAmount + simpleInterest;

    // Round simpleInterest and total to 2 decimal places
    simpleInterest = roundf(simpleInterest * 100) / 100;
    total = roundf(total * 100) / 100;

    // Print result
    printf("Simple Interest = %.2f\nTotal = %.2f", simpleInterest, total);

    return 0;
}