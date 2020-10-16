# Laboration 5
Marcus Roos
Maro1904

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ 
Debugger: MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
To learn about generic algorithms, standard library, more practice with 
templates as well as function objects (functors). We will be creating a list, 
fill it with values and then perform different manipulations on the list and 
its values.

## Procedures
We had a few different things that the manipulators were meant to be able to 
accomplish with the list, those were;
* User defines type, either double or integer
* User fills the list with 20 randomized values
* Sum for all the values will be calculated
* The median for each and every value will be calculated
* Search for the first value in the interval 1500-1900
* Divide all values by 2
* Swap positions of value #1 and #20, #2 and #19, #3 and #18 and so on
* Search for the max and min values in the list
* Sort the values in the list ascending
* Save the list to a file
* Empty the list of content
* Load in a file and its values, store in a list
* Print out all values in the list

Quite a hefty list, so I decided to start off with the bare minimum, I set up
a test program which consists of a sub menu, a main menu, choice options for 
the user and printing of main menu. In the main menu I also chose to store the list 
which meant the menu had to be of type typename and therefore a template,
this is because the user should be able to choose between double or integer
when first interacting with the program. Which means the sub menu needed to run
at the very start, once it were implemented it called the mainmenu which 
used the selected input to initialize and declare a listmanipulator
object consisting of an empty list. 

With the list loaded in the mainmenu all I had to do was call the different 
manipulators for this menu and make sure the program don't leave this 
menu until the user choose to quit and the list will always be 
accessible for the testprogram. If I wouldn't have done it this way I would
have to create a whole class for the test program as well and make sure the list
is declared as a private member only accessible by its private members.
I decided to go for this approach as it was the path of least resistance, and 
the focus here isn't to create a sturdy test program but to learn the STL.

I added the different manipulators in the ListManipulator class one by one, 
I first had to add a function to actually fill up the list as I won't be 
able to test the other functions if I have no values. I created a simple 
random number generator and integrated in a lambda function in a generate 
function, those values were then stored in the loaded list of the correct 
type. With a list full of values I added the other functions one by one, 
I simply worked my way down the list mentioned above with an exception of 
adding a way to print values for testing purposes first.

I added the write and read values to/from file last and realized pretty soon
that I need to be able to distinguish between double and integer values 
even when the values were stored on a file, to achieve this I simply created two
different files, one for integers and one for doubles.


## Discussion