/*
 * Assignment: Homework #2
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: C program to print your name and your age in a well-defined format.
 * */

#include <stdio.h>

int main() {
    // Max name size is 50
    char name[50];
    int age;

    // Get name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // Allows for full names

    //Remove '\n' character that fgets inserts at the end of name
    for (int i = 0; i < sizeof(name); ++i) {
        if (name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    // Get age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Make sure age >= 0
    while(age < 0) {
        printf("Your age can not be negative.\nEnter your age: ");
        scanf("%d", &age);
    }

    printf("My name is %s and my age is %d.", name, age);

    return 0;
}

