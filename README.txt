Nathan Moliterno
2-13-19 16:45

Purpose:
	The Purpose of this program is to take a set of integers and an empty
ternary tree, put those integers into the tree in the order they are given to
the program, and then print out the integers in symmetric order. The set of
integers is passed into the program via a textfile, wherein each integer is
separated by a space. The integers are printed such that the user can tell
wherin the tree each interger belongs. Calling the first datum of a node "a"
and the second "b", nodes are represented via the following notation:
(left child) a (middle child) b (right child).
	Additionally, the user is able to search the tree for a specific
integer value. The user is asked for an integer value to
search for, and the program searches the tree for it - all the while letting
the user know which path it's taking.

Compiling:
	To compile the program, simply type "make" into the command line under
the directory where the program files are located.

Running:
	To run the program, type "./TernaryTree " followed by either "test.txt"
or "data.ternary.txt" depending on which test you intend to run. test.txt
contains 20 integers, and data.ternary.txt contains 1000 integers.

Bugs:
	None

Cited Sources:
	I used a random number generator via the following link in order to
come up with the integer values in my own test:
	https://www.random.org/integers/

	I used a thread in a forum on stackoverflow.com in order to remind
myself how to properly read word by work (or in this case, integer by integer)
from a file. I mainly derived my understanding from a reply made by someone
named "Some programmer dude" on the site:
	https://stackoverflow.com/questions/20372661/read-word-by-word-from-
file-in-c
