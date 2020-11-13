; Assignment: Homework #5
; Name: Trey Manuszak
; ASU email: tmanusza@asu.edu
; Course: CSE240 TTh 1030-1145
; File Description: Main file to HW5 that contains various lisp functions 
; manipulating using control structures and recursive techniques to manipulate data.

; Function: multiply
; --------------------
; Function that multiplies two numbers.
;
; Parameters:
; 	num1: The multiplicand
;	num2: The multiplier
;
; Return:
;	The product of num1 * num2
(defun multiply (num1 num2)
	(* num1 num2)
)

; Function: maximum
; --------------------
; Function that searches a list of data for the largest value.
;
; Parameters:
; 	data: list of data
;
; Return:
;	The maximum value in data.
(defun maximum (data)
	(let ((largest (first data)))
		(dotimes (i (length data))
			(if (> (nth i data) largest)
				(setf largest (nth i data))
			)
		)
		largest
	)
)

; Function: average
; --------------------
; Function that returns the average of all numbers in a list.
;
; Parameters:
; 	data: list of data
;
; Return:
;	The average of all numbers in data.
(defun average (data)
	(let ((sum 0) (average 0))
		(dotimes (i (length data))
			(setf sum (+ sum (nth i data)))
		)
		(setf average (/ sum (length data)))
		average
	)
)

; Function: count-of
; --------------------
; Function that returns the number of times x shows up in the list, 
; not counting occurences in subarrays.
;
; Parameters:
;	item: item to count in the list
; 	data: list of data
;
; Return:
;	The number of times item shows up in the list.
(defun count-of (item data)
	(let ((total 0))
		(dotimes (i (length data))
			(if (equal item (nth i data))
				(setf total (1+ total))
			)
		)	
		total
	)
)

(defun test()
	(print (multiply 3 1))
	(print (maximum '(100 78 9 8 200)))
	(print (average '(1 2 3 4 5 6 7 8 9)))
	(print (count-of 'a '(a '(a c) d c a)))
	;(print (iterative-factorial 5))
	;(print (recursive-factorial 4))
	;(print (fibonacci 8))
	;(print (trim-at 'c '(a b c d e)))
	;(print (ackermann 1 1))
)

(test)

