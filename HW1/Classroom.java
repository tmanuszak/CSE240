/*
 * Assignment: Homework #1
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description: This file contains the layout of a classroom and methods to change and print it.
 * */

public class Classroom {
    private Student[][] arrangement;

    /**
     * Description: Constructor for Classroom. Initializes 2d array of Student.
     *
     * @param rowNum    is the number of rows to the Classroom.
     * @param columnNum is the number of columns in the Classroom.
     */
    public Classroom(int rowNum, int columnNum) {
        this.arrangement = new Student[rowNum][columnNum];

        //Initialize the seats to the default name "bar/foo"
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                this.arrangement[i][j] = new Student("bar/foo");
            }
        }
    }

    /**
     * Description: Getter for the student at a specific spot in the classroom.
     *
     * @param row is the row index of the student needed.
     * @param col is the column position of the student needed.
     * @return The Student is returned from the index specified.
     */
    private Student getStudent(int row, int col) {
        return this.arrangement[row][col];
    }

    /**
     * Description: Method to place a student if the seat is not taken.
     *
     * @param row  is the row index to place the student.
     * @param col  is the column index to place the student.
     * @param data is the student to be placed.
     */
    public boolean setStudentAt(int row, int col, Student data) {
        if (this.arrangement[row][col].toString().equals("bar.foo.")) {
            this.arrangement[row][col] = data;
            return true;
        } else {
            return false;
        }
    }

    /**
     * Description: Check to see if index is out of bounds for the classroom.
     * @param row  is the row index.
     * @param col  is the column index.
     * */
    public boolean isValid(int row, int col) {
        return row < this.arrangement[0].length && col < this.arrangement.length
                && row >= 0 && col >= 0;
    }

    /**
     * Description: Method to create a chart of the seating arrangement in the classroom.
     * */
    public String toString() {
        String str = "The current seating:";

        for (int i = 0; i < this.arrangement.length; i++) {
            str += "\n";
            for (int j = 0; j < this.arrangement[i].length; j++) {
                str += this.arrangement[i][j].toString() + " ";
            }
        }

        return str;
    }
}