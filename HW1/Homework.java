/*
 * Assignment: Homework #1
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Class with various methods which initializes arrays, prints arrays,
 * sorts arrays using selection sort, and calculates a factorial recursively.
 * */

public class Homework {

    /**
     * Description: Take an array of characters and change odd indices to 'a', else 'b'.
     * @param  chArray is an array of integers.
     * */
    public static void initializeArray(char[] chArray) {
        for (int i = 0; i < chArray.length; i++) {
            if (i % 2 == 1) { //if index odd, replace with 'a', else 'b'
                chArray[i] = 'a';
            } else {
                chArray[i] = 'b';
            }
        }
    }

    /**
     * Description: Take an array of characters and print to the console using a for loop.
     * @param chArray is an array of characters.
     * */
    public static void printArray(char[] chArray) {
        for (int i = 0; i < chArray.length; i++) {
            System.out.print(chArray[i]);
            System.out.print(' ');
        }
        System.out.println();
    }

    /**
     * Description: Take an array of characters and sort in descending order using the selection sort method.
     * @param unsortedChars is an array of characters.
     * */
    public static void selectionSort(char[] unsortedChars) {
        int len = unsortedChars.length;

        for (int i = 0; i < len - 1; i++) {
            int maxIndex = i;

            //Find the index of the largest element still unsorted
            for (int j = i + 1; j < len; j++) {
                if (unsortedChars[j] > unsortedChars[maxIndex]) {
                    maxIndex = j;
                }
            }

            //Swap the largest element with the first element
            char temp = unsortedChars[maxIndex];
            unsortedChars[maxIndex] = unsortedChars[i];
            unsortedChars[i] = temp;
        }
    }

    /**
     * Description: A recursive method to calculate the factorial of an integer.
     * @param number is the integer to find the factorial of.
     * @return Returns the factorial of number, otherwise assume number is 0, which returns 1.
     * */
    public static int factorial(int number) {
        if (number > 2) {
            //Multiply by the factorial of n-1
            number *= factorial(number - 1);
        } else if (number == 0) {
            return 1; //In case number == 0
        }

        return number;
    }

    /**
     * Description: Method to test the above methods
     * */
    public static void main(String[] args) {
        char [] a = {'2', '5', '7', '9', '2', '3', '1', '7', '9', '0'};
        char [] b = {'p', 'q', '8', '6', '9', '5', '3', '1', '6'};
        int [] c = {4, 2, 5, 3, 1};

        // testing initializeArray
        printArray(a); // print: 2 5 7 9 2 3 1 7 9 0
        initializeArray(a);
        printArray(a); // print: b a b a b a b a b a

        // testing selectionSort
        printArray(b); // print: p q 8 6 9 5 3 1 6
        selectionSort(b);
        printArray(b); // print: q p 9 8 6 6 5 3 1

        // testing factorial
        System.out.println(factorial (5)); //print: 120
        System.out.println(factorial (c[0])); //print: 24
        System.out.println(factorial (c[3])); //print: 6
    }
}