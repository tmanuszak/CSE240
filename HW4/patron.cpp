/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Source file for the Patron class, which contains information and methods for a patron of a theatre.
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
	strcpy(lastName, "###");
	strcpy(firstName, "###");
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
	strcpy(firstName, tokens);
	tokens = strtok(NULL, "/");
	strcpy(lastName, tokens);
}

/*
Function: getLastName
--------------------
Function returns the last name of a patron.

Return:
	char* name : The pointer to the Patron's last name.	
*/
char* Patron::getLastName() {
	return lastName;
}

/*
Function: getFirstName
--------------------
Function return the first name of a patron.

Return:
	char* : The pointer to the Patron's first name.	
*/
char* Patron::getFirstName() {
	return firstName;
}

/*
Function: toString
--------------------
Function return the initials of a patron.

Return:
	char* : The pointer to the Patron's initials.	
*/
char* Patron::toString() {
	char* initials = new char[5];
	char* first = this->getFirstName();
	char* last = this->getLastName();
	initials[0] = first[0];
	initials[1] = '.';
	initials[2] = last[0];
	initials[3] = '.';
	initials[4] = '\0';
	return initials;
}

/*
Destructor
--------------------
Destructor for the Patron class.
*/
Patron::~Patron() {

}
