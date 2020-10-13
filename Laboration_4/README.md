# Laboration 4
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
The purpose of this assignment is to develop an understanding of how exceptions 
work, and to some degree templates. 

## Procedures
I started off by creating a test environment to test out the classes and their 
functions one by one, as simple as possible and just calling it straight from
the main.cpp. At first I had to verify the two files that are supposed to open 
up, and if not found, throw an error, which meant the openFiles() function in the 
DataFileReader class had to be created, at first I declared the if/ofstreams here
but realized rather soon it wasn't going to work as those streams have to be used 
in different functions of the program, I instead moved them to declare them
as private members and initialized them in this function instead. 
I started off by opening one file, if it couldn't be opened an 
error will be throw, then I did the same for the second file. If either or 
of those files couldn't be opened it means they don't exist on the computer, 
and a runtime error will terminate the program and return an error to the user, 
informing them of the issue. I used this to determine the preconditions 
of the next function;

The readNextValue function had to be configured to properly read the instream 
from values.dat and verify each and every value as well as convert it to a 
double (type determined by the template argument), if it fails to convert the 
value it should instead be converted to a string and stored in ReadErrors.dat.
I achieved this by setting an exception mask with the relevant error codes, 
if the value cannot be converted to a double it can't possibly be a 
numerical values, therefore an exception will be thrown and the bad value will
be written to the error file. With those two functions in place I moved on to
the DataFilter function which will be the classic utilizing the readNextValue
function.

In the DataFilter classed I added the necessary members to make it run smoothly
without any weird hiccups, I declared variables to keep track of statistics
and min and max values to determine if a value is within the specified range, 
if not, the value should be filtered and stored elsewhere. This class requires a
pointer to a DataFileReader object, and this pointer will be declared when
the constructor is being called. It will use the DataFileReader object created 
in the main which were used to call the openFiles() function to determine if 
the two required files actually do exist. 

DataFilter consists of only one function, and its entire purpose is to filter 
through the values referenced by the readNextValue function in the DataFileReader 
class, as well as keep track of statistics. To achieve this I created an internal
loop which will run all until readNextValue returns false, as that function 
will only return false once it has reached end of line I can consistently call
it over and over and expect true to be returned until eof. The value that's referred
to by this function will be held in getNextFunction and evaluated at a few 
different levels, first of all it will verify that a value is actually 
held, as mentioned earlier it will hold false if not, or true if a value is found. 

The held value will be compared to the given minimum and maximum values set
by the constructor, if its outside the given interval a range_error will be 
thrown and the value along with the given range_error string will be written 
to a file called "RangeErrors.dat". If a value is held, and this value is within
the given interval the amount for numerical values read will increase by one, 
and a sum variable will be increased by that of the read value, this process will
loop until the readNextValue function returns false, if it does, it has 
reached the end of line. At this point the getNextValue function will leave the 
while loop and open the "ReadErrors.dat" file and start counting the amount of 
newlines, the amount of newlines will be added to a temporary variable, once 
it reaches end of file the "ReadErrors.dat" instream will close, the linecounter
will decrease by one to accommodate for the extra newline found at the end 
of a file. The amount of numerical values read will be deducted by this 
line counter, the average of the values read will be calculated, and the 
final results printed on the screen. This is all done within the getNextValue
function.

## Discussion
This assignment proved to be more challenging than I had initially thought. 
While the concept of templates and exceptions both seem straight forward enough 
it's everything around as well as the restrictions that made it tougher, not
being able to use a h/cpp combo threw me off at first, and while I found a few 
different solutions I decided to put all the code in .h files, after some more 
reading this seems to be the standard, but the .h files should be refractored 
into .hpp files which I will definitely do for assignment 5 at the start. 
While there is no different between .h and .hpp files its used to distinguish 
the different between a regular header file, and a template file. 

I had no bigger issues getting the exceptions working as they should, but I did 
have a few hiccups with the templates but they were all very minor and were 
resolved within the minute. Biggest challenge I had were getting the reading 
of files working as I wanted, while it worked close to what it were ought to, 
I still got the amount counter to tick up for all the values stored in 
"ReadErrors.dat". I didn't manage any "clean" solution for this, and it feels 
like my current solution is very crude, however it gets the job done and 
produces the wanted results without any kind of cheesing. 

To find the "ReadErrors.dat" and "Values.dat" files I decided to simply 
move those two files from the _Resources folder and initialize 
two strings in the main.cpp with their respective names. 
I preferred to do it this way as file structure can be different 
from user to user and if the files are always next to the 
source folder different file structure won't be be the cause to failing 
to find those files. If it wasn't allowed to move those files I would simply 
use ("../../_Resources/Lab_4/Values.dat", "../../_Resources/Lab_4/ReadErrors.dat")
when initializing the strings and using those parameters for opening the files.
It would take two steps up to where the _Resources folder is located, enter it, 
navigate to Lab_4 and find the "Values.dat" and "ReadErrors.dat" files.

The pre/post conditions were a bit strange to handle at times, the 
getNextValues precondition were meant to check whether an earlier call to 
getNextValue had returned true or false, if true getNextValue can keep on 
running, if false it should not be called. I had a bit trouble getting this 
to work as calling a function within itself would cause an endless loop 
and crash the program. I could solve this by either adding another variable and
extending the code, this variable would be calling the getNextValue function,
store the result in itself and keep being called at the start of the getNextValue.

However I didn't really see a smooth implementation for this and it didn't feel
natural whatsoever, instead I let the getNextValue function call the 
readNextValue function from the DataFileReader instead, as that function will 
return false once end of file has been reached, and thats when I want the getNextValue
function to stop running, besides, that's where the value is coming from, so
somehow letting getnextvalue call itself, or store the result in a different 
variable just to verify that it hasn't been ran yet when we in fact know for sure
it won't ever happen with the current code. I would deem this necessary if the 
program had a menu where the user could choose to run the program, in that case 
a bool would be declared and changed to false once getNextValue returns false, 
and calling the getNextValue function again would be impossible to do.
It just seems like a lot of extra work for no purpose at this point, if I 
have to change it, Fx me and I will put together a fix for this within 
the main.cpp file.