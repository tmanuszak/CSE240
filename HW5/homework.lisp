; Assignment: Homework #5
; Name: Trey Manuszak
; ASU email: tmanusza@asu.edu
; Course: CSE240 TTh 1030-1145
; File Description: Main file to HW5 that contains various lisp functions 
; using control structures and recursive techniques to manipulate data.

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

; Function: iterative-factorial
; --------------------
; Function that calculates the factorial of an integer iteratively
;
; Parameters:
;	num: the integer to calculate the factorial of
;
; Return:
;	The factorial of number.
(defun iterative-factorial (num)
	(let ((sum 1))
		(dotimes (i num)
			(setf sum (* sum (1+ i)))
		)
		sum
	)
)

; Function: recursive-factorial
; --------------------
; Function that calculates the factorial of an integer recursively.
;
; Parameters:
;	num: The number to calculate the factorial of.
;
; Return:
;	The factorial of num.
(defun recursive-factorial (num)
	(if (<= num 1)
		1
		(* num (recursive-factorial (1- num)))
	)
)

; Function: fibonacci
; --------------------
; Function that calculates the nth fibonacci number.
;
; Parameters:
;	num: The nth fibonacci number to find.
;
; Return:
;	The nth fibonacci number.
(defun fibonacci (num)
	(if (= num 0)
		0
		(if (= num 1)
			1
			(+ (fibonacci (- num 1)) (fibonacci (- num 2)))
		)
	)
)

; Function: trim-at
; --------------------
; Function that trims an array of data up to and including a certain value.
;
; Parameters:
;	item: item to trim the list at
; 	data: list of data
;
; Return:
;	The trimmed list.
(defun trim-at (item data)
	(let ((subdata '()) (flag nil))
		(dotimes (i (length data))
			(if (equal flag nil)
				(setf subdata (subseq data 0 (+ i 1)))
			)
			(if (equal item (nth i data))
				(setf flag t)
			)
		)
		subdata
	)
)

; Function: ackermann
; --------------------
; Function that performs the ackermann function.
;
; Parameters:
;	x: the x value of the ackermann input
; 	y: the y value of the ackermann input
;
; Return:
;	y + 1 if x = 0
;	A(x-1, 1) if y = 0
;	A(x-1, A(x,y-1)) else
(defun ackermann (x y)
	(let ((result -1))
		(if (and (= x 0) (/= y 0))
			(setf result (+ y 1))
		)
		(if (and (/= x 0) (= y 0))
			(setf result (ackermann (- x 1) 1))
		)
		(if (and (/= x 0) (/= y 0))
			(setf result (ackermann (- x 1) (ackermann x (- y 1))))
		)
		result
	)
)			

(defun test()
	(print (multiply 3 1))
	(print (maximum '(5 78 9 8 3)))
	(print (average '(1 2 3 4 5 6 7 8 9)))
	(print (count-of 'a '(a '(a c) d c a)))
	(print (iterative-factorial 5))
	(print (recursive-factorial 4))
	(print (fibonacci 8))
	(print (trim-at 'c '(a b c d e)))
	(print (ackermann 1 1))
)

(test)

