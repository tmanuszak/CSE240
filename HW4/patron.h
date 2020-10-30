/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Header file for the Patron class, which contains information and methods for a patron of a theatre.
 * */

class Patron {
	public:
		/*
		Constructor
		--------------------
		Constructor for the Patron class that initializes lastName and firstName to "###".		  
		*/
		Patron();
		
		/*
		Costructor 
		--------------------
		Constructor for the Patron class that initializes firstName and lastName using strtok.

		Parameters:
			char* : The pointer to the Patron name information.	
		*/
		Patron(char*);

		/*
		Function: getLastName
		--------------------
		Function return the last name of a patron.

		Return:
			char* : The pointer to the Patron's last name.	
		*/
		char* getLastName();

		/*
		Function: getFirstName
		--------------------
		Function return the first name of a patron.

		Return:
			char* : The pointer to the Patron's first name.	
		*/
		char* getFirstName();

		/*
		Function: toString
		--------------------
		Function return the initials of a patron.

		Return:
			char* : The pointer to the Patron's initials.	
		*/
		char* toString();

		/*
		Destructor
		-------------------
		*/
		~Patron();

	private:
		char lastName [25];
		char firstName [25];
};
