/*
* Assignment: Homework #1
* Name: Trey Manuszak
* ASU email: tmanusza@asu.edu
* Course: CSE240 TTh 1030-1145
* File Description:
* */

/*
import java.util.Scanner;

public class HomeworkTwo {
	
	public static void main(String[] args) {
		
		Classroom classroom;
		Student data;
		int row, col, rowNum, colNum;
		String info;
		Scanner sc = new Scanner(System.in);
		
		System.out.println("How many rows do you want?");
		rowNum = sc.nextInt();
		
		System.out.println("How many columns do you want?");
		colNum = sc.nextInt();
		
		classroom = new Classroom(rowNum, colNum);
		
		System.out.println("Capture a student information (name/lastname) or enter \"Q\" to quit.");
		info = sc.next();
		
		while(!info.equalsIgnoreCase("Q")) {
			
			data = new Student(info);
			
			System.out.println("Capture the row number where the student wants to sit:");
			row = sc.nextInt();
			System.out.println("Capture the column number where the student wants to sit:");
			col = sc.nextInt();
			
			if(classroom.isValid(row, col) == false) {
				System.out.println("\n row or column number is not valid.");
				System.out.println("A student " + data.getFirstName() + " " + data.getLastName() + " is not assigned to a seat.");
			} else {
				if(classroom.setStudentAt(row, col, data) == true) {
					System.out.println("\n The seat at row " + row + " and column " + col + " is assigned to " + data.toString());
					System.out.println(classroom);
				} else {
					System.out.println("\n The seat at row " + row + " and column " + col + " is taken.");
				}
			}
			
			System.out.println("Capture a student information (name/lastname) or enter \"Q\" to quit.");
			info = sc.next();	
		}
		
		sc.close();
	}
}*/
