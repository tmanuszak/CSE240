/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Source file with various methods for arrays.
 * */

#include <iostream>
using namespace std;
#include "homework.h"

/*
Constructor
--------------------
*/
Homework::Homework() {  

}

/*
Function:  initializingArray
--------------------
Function to initialize even indicies to 1 and odd indices to 0.

Parameters:
	int* :  Pointer to the array.
	int  :  Size of the array.		  
*/
void Homework::initializingArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			arr[i] = 1;
		} else {
			arr[i] = 0;
		}
	}
}

/*
Function:  printingArray
--------------------
Function to print an array of ints.

Parameters:
	int* :  Pointer to the array.
	int  :  Size of the array. 
*/
void Homework::printingArray(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		cout << arr[i] << ", ";
	}
	cout << arr[size - 1] << endl;
}

/*
Function:  selectionSort
--------------------
Function to sort an array in ascending order using selection sort.
Parameters:
	int* :  Pointer to the array.
	int  :  Size of the array.
*/
void Homework::selectionSort(int* arr, int size) {
	int smallIndex = 0;
	// Shrinking window
	for (int i = 0; i < (size - 1); i++) {
		smallIndex = i;
		// Find smallest index
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[smallIndex]) {
				smallIndex = j; // New smallest index
			}
		}

		// Swap
		int temp = arr[smallIndex];
		arr[smallIndex] = arr[i];
		arr[i] = temp;
	} 	
}

/*
Function:  factorial
--------------------
Function to calculate the factorial of an integer recursively.
Parameters:
	int  :  The factorial to be calculated.		   
Returns:
    	int  :  The factorial of the integer.
*/
int Homework::factorial(int num) {
	if (num >= 2) {
		return num * factorial(num - 1);
	} else {
		return 1;
	}
}

