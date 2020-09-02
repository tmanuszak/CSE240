/*
 * Assignment: Homework #1
 * Name: Trey Manuszak
 * ASU email: tmanusza@asu.edu
 * Course: CSE240 TTh 1030-1145
 * File Description:
 * */

public class Student {
    private String firstName;
    private String lastName;

    /**
     * Description: Contructor for the Student class.
     * @param info is a String of the form "firstname/lastname".
     * */
    public Student(String info) {
        String[] arr = info.split("/");
        this.firstName = arr[0];
        this.lastName = arr[1];
    }

    /**
     * Description: Getter for the firstName variable.
     * @return String of the firstName.
     * */
    public String getFirstName() {
        return firstName;
    }

    /**
     * Description: Getter for the lastName variable.
     * @return String of the lastName.
     * */
    public String getLastName() {
        return lastName;
    }

    /**
     * Description: Method to return first and last initial of student, ignoring bar and foo.
     * @return String of the lastName.
     * */
    public String toString() {
        if (firstName.equals("bar") && lastName.equals("foo")) {
            return "bar.foo.";
        } else {
            return this.firstName.charAt(0) + "." + this.lastName.charAt(0) + ".";
        }
    }
}