#include "patron.h”
#include "theatre.h”

void main()
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
        cout << "\nA patron information is read.";
        // printing information.
        cout << patronInfo;
        // patron
        tempPatron = new Patron(patronInfo);
        // Ask a user to decide where to seat a patron by asking
        // for row and column of a seat
        cout << "Please enter a row number where the patron wants to sit.";
        cin >> row;
        cout << "Please enter a column number where the patron wants to sit.";
        cin >> col;
        // Checking if the row number and column number are valid
        // (exist in the theatre that we created.)
        if (*theatre.checkBoundaries(row, col) == false)
        {
            cout << "\nrow or column number is not valid.";
            cout << "A patron" << (*tempPatron).getFirstName() << " " << (*tempPatron).getLastName() << " is not assigned a seat.";
        }
        else
        {
            // Assigning a seat for a patron
            if ((*theatre).assignPatronAt(row, col, tempPatron) == true)
            {
                cout << "\nThe seat at row " << row << " and column " << col << " is assigned to the patron, " << (*tempPatron).toString();
                (*theatre).toString();
            }
            else
            {
                cout << "\nThe seat at row " << row << " and column " << col << " is taken.";
            }
        }
        // Read the next patronInfo
        cout << "Please enter a patron information or enter \"Q\" to quit.";
        /*** reading a patron's information ***/
        cin >> patronInfo;
    }
}