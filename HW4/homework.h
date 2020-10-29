/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Header file with various methods.
 * */

class Homework {
	public:
		/*
		Constructor
		--------------------
		*/
		Homework();

		/*
		Function:  initializingArray
		--------------------
		Function to initialize even indicies to 1 and odd indices to 0..
		Parameters:
			int* :  Pointer to the array.
			int  :  Size of the array.		  
		*/
		void initializingArray(int*, int);

		/*
		Function:  printingArray
		--------------------
		Function to print an array of ints.
		Parameters:
			int* :  Pointer to the array.
			int  :  Size of the array. 
		*/
		void printingArray(int*, int);

		/*
		Function:  selectionSort
		--------------------
		Function to sort an array in ascending order using selection sort.
		Parameters:
			int* :  Pointer to the array.
			int  :  Size of the array.
		*/
		void selectionSort(int*, int);

		/*
		Function:  factorial
		--------------------
		Function to calculate the factorial of an integer recursively.
		Parameters:
			int  :  The factorial to be calculated.		   
		Returns:
		    	int  :  The factorial of the integer.
		*/
		int factorial(int);
};
