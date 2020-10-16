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
Everything that we did in this assignment felt like something we had done before,
but in a more complicated manner. For instance we used lists here instead of 
array or vector, we used iterators to fill a list instead of push_back, 
we used pre-determined algorithms with iterators to find minimum and
maximum values instead of writing our own search algorithm as we had done in the 
past. However there were a lot of different tasks that the program should be able
to accomplish, and almost everything that we had to do here with the requirements
we had to conform to made it new. 

We had to conform to different standard libraries to achieve the expected
results instead of using the methods we've grown used to. For instance we 
used the accumulate function to calculate the sum of a list, in the past 
we have had to calculate the sum in a vector or array of values, and 
previously we initialized a variable of the same type as the vector, 
created a loop for the whole vector and added the values to the sum
variable, one by one, before finally returning it. With the accumulate function 
it seemed like it achieved all of this all by it self, but in reality I think 
this function, and all the rest of similar structure is simply hiding the crudeness
beneath the surface and making it easier for the programmer. We've grown used
to the harsh and more complicated ways, instead of learning the easy way
first. 

I made note about this in the ListManipulator.hpp file as well but I wasn't 
entirely sure of how the "find first 1500-1900" function were meant to work,
so I included the two ways I struggled between. By default it will create a 
dummy list with the same contents as the main list, sort it ascending and return
the first value within the said interval, as this would be the "first value 
in the interval" in my mind. I wasn't entirely sure that has the intended result, 
so I included the other way of doing it as well, which will basically return 
the very first value encountered which lies in the 1500-1900 interval, despite 
not being the closest one to 1500, I added comment section so its a matter of 
simply deleting and adding comment blocks to switch between the two. 

I hadn't really used lambda functions prior to this assignment but realized 
pretty quickly they are really handy to have. For instance for filling up 
the vector with randomized numbers I had a whole separate function created 
which the generate called over and over to populate the list until the 
20 mark was reached. However I had no use for this function elsewhere 
and I knew exactly when and how it will be used, when filling up the list. A 
lambda expression made this much easier and neater of a solution as I could 
include it in the generate function as a lambda function instead of a whole
separate function. Besides, it saves a lot of redundant code.

All in all I really enjoyed this assignment, everything felt so easy while still
being foreign to me, thanks to the methods we've used in the past I never got 
stuck for more than a couple of minutes at a time, as I knew how it worked at 
a more basic and raw level. Except this time around I got to use already developed,
proven functions and libraries which do the job for me, so I don't have to 
rewrite what's already done basically. The libraries are there for a reason, to
be used, and if there's something I don't like about them I can always write my 
own functions and algorithms as I know how they will work at the basic level.