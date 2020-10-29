/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Main file to HW4_1.
 * */

#include <iostream>
#include "homework.h"

using namespace std;

int main() {
    int a [10] = {3, 5, 6, 9, 12, 13, 16, 17, 18, 20};  
    int b [6]= {18, 16, 19, 3 ,14, 6}; 
    int c [5]= {5, 2, 4, 3, 1};
    
    Homework h;

    // testing initializingArray 
	h.printingArray(a, 10); // print: 3, 5, 6, 9, 12, 13, 16, 17, 18, 20
    h.initializingArray(a, 10);
    h.printingArray(a, 10); // print: 1, 0, 1, 0, 1, 0, 1, 0, 1, 0

    // testing selectionSort
    h.printingArray(b, 6); // print: 18, 16, 19, 3 ,14, 6
    h.selectionSort(b, 6);
    h.printingArray(b, 6); // print: 3, 6, 14, 16, 18, 19

    // testing factorial
    cout << "Factorial of 5 = " << h.factorial (5) << endl; //print: 120

    c[0] = h.factorial (c[0]);
    c[1] = h.factorial (c[2]);
    h.printingArray(c, 5); // print: 120, 24, 4, 3, 1
	
    return 0;
}
