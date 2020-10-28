/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Program that simulates a games board that adds, removes, and moves game pieces.
 * */

#include <iostream>
using namespace std;
#include "homework.h"

Homework::Homework() { //constructor 

}

void Homework::initializingArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			arr[i] = 1;
		} else {
			arr[i] = 0;
		}
	}
}

void Homework::printingArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

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

int Homework::factorial(int num) {
	if (num >= 2) {
		return num * factorial(num - 1);
	} else {
		return 1;
	}
}

