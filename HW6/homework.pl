% Assignment: Homework #6
% Name: Trey Manuszak
% ASU email: tmanusza@asu.edu
% Course: CSE240 TTh 1030-1145
% File Description: Main file to HW6 showcases knowledge of Prolog
%			by using facts, rules, and functions. This program
%			was compiled using the GNU Prolog Compiler.

% Question 2 "Weather is cold. If weather is cold, everyone likes it."
cold(weather).
likes(Person, Weather) :- cold(Weather).

% Question 3
% ?- N is -(+(5,6),4).
% ?- N is (5+6)-4.
% Both of the querries above produce the same result because arithmetic
% expressions can be written in infix and prefix notation for Prolog,
% according to the textbook.

% Question 4 
% Implement a couple facts and answer the questions:
% "Who can travel?" (?- travels(X).)
% "Who is healthy and wealthy?" (?- healthy(X), wealthy(X).)
woman(jane).
man(john).
healthy(john).
healthy(jane).
wealthy(jane).
traveler(Person) :- healthy(Person) , wealthy(Person).
travels(Person) :- traveler(Person).

% Question 5
vegetarian(jose).
vegetarian(james).
vegetable(carrot).
vegetable(egg_plant).
likes(jose, X) :- vegetable(X).
loves(Who, egg_plant) :- vegetarian(Who).
%--------------
% vegetable(X). 
% Answer:
% X = carrot
% X = egg_plant
% yes
%----------------
% vegetable(tomato).
% Answer:
% no
%----------------
% likes(jose, What).
% Answer (if question 5 program is in same file as question 2 since likes calls the function
%		in question 1 if they are in the same file):
% What = weather
% yes
% Answer (if question 5 is in seperate file from question 2):
% What = carrot
% What = egg_plant
% yes
%----------------
% likes(Who, egg_plant).
% Answer (if question 5 program is in same file as question 2 since likes calls the function
%		in question 1 if they are in the same file):
% no
% Answer (if question 5 is in seperate file from question 2):
% Who = jose
% yes
%-----------------
% loves(Who, egg_plant).
% Answer:
% Who = jose
% Who = james
% yes

% Question 6
 fib(1,1).
 fib(2,1).
 fib(N,R) :- N >= 3, N1 is N-1, N2 is N-2, fib(N1,R1), fib(N2,R2), R is R1+R2.
%
% a: Let F_n denote the nth fibonacci number. Then fib(1,1). represents F_1 = 1
%	and fib(2,1). represents F_2 = 1. Then, the rule fib(N,R) is stated such
% 	that if N >= 3, then let N1 = N-1 and N2 = N-2, then find fib(N1,R1) and
%	fib(N2,R2) recursively, which allows for R = R1 + R2. Thus, F_N = R.
%
% b: fib(3,R) is calculated by calling fib(2,R1) and fib(1,R2), which returns
%	R1 = 1 and R2 = 1, repsectively. Thus, it calculates R = R1 + R2 = 1 + 1 = 3,
%	which then returns R = 3 to the console.
%
% c: fib(9, R). returns R = 34
%	fib(9,9). returns no

% Question 7
% a: reads_history(john).
% b: likes_sparky(Person) :- asu_student(Person).
% c: ?- likes_sparky(Person).
% d: hates(jane, City) :- small(City), crowded(City).

% Question 8
sum(X, Y) :- Y is (X * (X + 1)) / 2.
