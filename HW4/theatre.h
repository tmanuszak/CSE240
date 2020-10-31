/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Header file for the theatre class which contains a 2d arrangement of Patrons.
 * */

class Theatre {
	public:
		/*
		Constructor
		--------------------
		Constructor for the Theatre class that creates a two-dimensional array of Patrons.

		Parameters:
			const int : row dimension of the theatre.
			const int : col dimension of the theatre.
		*/
		Theatre(int, int);

		/*
		Function: getPatronAt
		--------------------
		Function that returns the patron in the theatre.

		Parameters:
			int : row of the Patron.
			int : col of the Patron.

		Return:
			Patron* : pointer of the desired Patron.
		*/
		Patron* getPatronAt(int, int);

		/*
		Function: assignPatronAt
		--------------------
		Function that assigns a Patron to a location if it is available.

		Parameters:
			int : row of the assignment.
			int : col of the assignment.
			Patron* : pointer of the Patron to be assigned.

		Return:
			bool : true if Patron was able to be assigned, false else.	
		*/
		bool assignPatronAt(int, int, Patron*);

		/*
		Function: checkBoundaries
		--------------------
		Function that checks if the desired location is valid.

		Parameters:
			int : row of the location.
			int : col of the location.	

		Return:
			bool : true if the location is valid, false else.	
		*/
		bool checkBoundaries(int, int);

		/*
		Function: toString
		--------------------
		Function returns a map of the arrangement.

		Return:
			char* : pointer to the string of the arrangement.	
		*/
		char* toString();

		/*
		Destructor
		-------------------
		Destructor for the Theatre class.
		*/
		~Theatre();

		Patron** arrangement;
		int rowSize; // How many rows the theatre has.
		int colSize; // How many columns the theatre has.
};
