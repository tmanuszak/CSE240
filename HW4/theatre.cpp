/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Source code file for the theatre class which contains a 2d arrangement of Patrons.
 * */

#include <cstring>
#include <iostream>
using namespace std;
#include "patron.h"
#include "theatre.h"


/*
Constructor
--------------------
Constructor for the Theatre class that creates a two-dimensional array of Patrons.

Parameters:
	const int row : row dimension of the theatre.
	const int col : col dimension of the theatre.
*/
Theatre::Theatre(int row, int col) {
	arrangement = new Patron*[row];
	for (int i = 0; i < row; i++) {
		arrangement[i] = new Patron[col];
		for (int j = 0; j < col; j++) {
			arrangement[i][j] = Patron();
		}
	}
	rowSize = row;
	colSize = col;
}

/*
Function: getPatronAt
--------------------
Function that returns the patron in the theatre.

Parameters:
	int row : row of the Patron.
	int col : col of the Patron.

Return:
	Patron* : pointer of the desired Patron.
*/
Patron* Theatre::getPatronAt(int row, int col) {
	return &(arrangement[row][col]);
}

/*
Function: assignPatronAt
--------------------
Function that assigns a Patron to a location if it is available.

Parameters:
	int row : row of the assignment.
	int col : col of the assignment.
	Patron* pat : pointer of the Patron to be assigned.

Return:
	bool : true if Patron was able to be assigned, false else
*/
bool Theatre::assignPatronAt(int row, int col, Patron* pat) {	
	if(strcmp(this->getPatronAt(row, col)->getFirstName(), "###") == 0 
		&& strcmp(this->getPatronAt(row, col)->getLastName(), "###") == 0) {
		arrangement[row][col] = *pat;
		return true;
	}
	return false;
}

/*
Function: checkBoundaries
--------------------
Function that checks if the desired location is valid.

Parameters:
	int row : row of the location.
	int col : col of the location.	

Return:
	bool : true if the location is valid, false else.	
*/
bool Theatre::checkBoundaries(int row, int col) {
	if(row >= 0 && row < rowSize && col >= 0 && col < colSize) {
		return true;
	} else {
		return false;
	}
}

/*
Function: toString
--------------------
Function returns a map of the arrangement.

Return:
	char* : pointer to the string of the arrangement.	
*/
char* Theatre::toString() {
	char* str = new char[0];
	strcpy(str, "");	
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			str = strncat(str, arrangement[i][j].toString(), sizeof(arrangement[i][j].toString()));
			str = strncat(str, " ", sizeof(" "));
		}
		str = strncat(str, "\n", sizeof("\n"));
	}
	return str;
}	

/*
Destructor
-------------------
Destructor for the Theatre class.
*/
Theatre::~Theatre() {
	int rowSize = sizeof(arrangement) / sizeof(arrangement[0]);
	int colSize = sizeof(arrangement[0]) / sizeof(Patron);
	for (int i = 0; i < rowSize; i++) {
		delete[] arrangement[i];
	}
}
