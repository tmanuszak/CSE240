/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Main file to HW4_1.
 * */

#include <cstring>
#include <iostream>
using namespace std;
#include "patron.h"

/*
Constructor
--------------------
Constructor for the Patron class that initializes lastName and firstName to "###".		  
*/
Patron::Patron() {
	lastName = "###";
	firstName = "###";
}		

/*
Costructor 
--------------------
Constructor for the Patron class that initializes firstName and lastName using strtok.

Parameters:
	char* name : The pointer to the Patron name information.	
*/
Patron::Patron(char* name) {
	char* tokens;
	tokens = strtok(name, "/");
	firstName = tokens[0];
	lastName = tokens[1];
}

/*
Function: getLastName
--------------------
Function return the last name of a patron.

Return:
	char* name : The pointer to the Patron's last name.	
*/
char* Patron::getLastName() {
	return &lastName;
}

/*
Function: getFirstName
--------------------
Function return the first name of a patron.

Return:
	char* : The pointer to the Patron's first name.	
*/
char* Patron::getFirstName() {
	return &firstName;
}

/*
Function: toString
--------------------
Function return the initials of a patron.

Return:
	char* : The pointer to the Patron's initials.	
*/
char* toString() {
	char initials[4];
	initials[0] = firstName[0];
	initials[1] = '.';
	initials[2] = lastName[0];
	initials[3] = '.';
	return &initials;
}

/*
Destructor
--------------------
Destructor for the Patron class.
*/
Patron::~Patron() {

}
