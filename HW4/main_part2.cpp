/*
 * Assignment: Homework #4
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: Program that builds a theatre and fills it with patrons.
 * */

#include <iostream>
using namespace std;
#include "patron.h"
#include "theatre.h"

int main()
{
    Theatre *theatre;
    Patron *tempPatron;
    int row, col, rowNum, columnNum;
    char patronInfo[25];

    // Ask a user to enter a number of rows for a theatre seating
    cout << "Please enter a number of rows for a theatre seating.";
    cin >> rowNum;
    // Ask a user to enter a number of columns for a theatre seating
    cout << "Please enter a number of columns for a theatre seating.";
    cin >> columnNum;

    // theatre_seating
    theatre = new Theatre(rowNum, columnNum);
    cout << "Please enter a patron information or enter \"Q\" to quit.";
    /*** reading a patron's information ***/
    cin >> patronInfo;

    /* we will read line by line **/
    while (patronInfo != "Q" || patronInfo != "q")
    {
        cout << "A patron information is read.\n";
        // printing information.
        cout << patronInfo;
        // patron
        tempPatron = new Patron(patronInfo);
        // Ask a user to decide where to seat a patron by asking
        // for row and column of a seat
        cout << "\nPlease enter a row number where the patron wants to sit.";
        cin >> row;
        cout << "Please enter a column number where the patron wants to sit.";
        cin >> col;
        // Checking if the row number and column number are valid
        // (exist in the theatre that we created.)
        if ((*theatre).checkBoundaries(row, col) == false)
        {
            cout << "Row or column number is not valid.";
            cout << "\nA patron " << (*tempPatron).getFirstName() << " " << (*tempPatron).getLastName() << " is not assigned a seat.";
        }
        else
        {
            // Assigning a seat for a patron
            if ((*theatre).assignPatronAt(row, col, tempPatron) == true)
            {
                cout << "The seat at row " << row << " and column " << col << " is assigned to the patron, " << (*tempPatron).toString();
                cout << (*theatre).toString();
            }
            else
            {
                cout << "The seat at row " << row << " and column " << col << " is taken.";
            }
        }
        // Read the next patronInfo
        cout << "\nPlease enter a patron information or enter \"Q\" to quit.";
        /*** reading a patron's information ***/
        cin >> patronInfo;
    }
    return 0;
}
