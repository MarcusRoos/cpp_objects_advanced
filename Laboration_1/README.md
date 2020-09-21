# Laboration 1

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ 
Debugger: MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
The purpose of this lab is to learn dynamic memory allocation and the usage of smart pointers, more specifically unique pointers contained in the “memory” library. We will also be learning how to accommodate our program to follow pre- and postconditions. The precondition will check whether a requirement is fulfilled before calling a function and the postcondition will make sure a specific requirement is fulfilled once the function has been called and finished.


## Procedures
In this lab we are meant to create a dynamic allocated array using unique pointers. The program should meet certain pre and postconditions, to fulfill these requirements we need to use different statements before and after calling functions. To get started a queue-class were created, this queue class had variables to keep track of the queues head, tail, the maximum capacity of the queue as well as current amount of elements in the queue, it also contains a unique ptr array using the custom type “Type” which is an alias for int. 

The queue class takes care of all the necessities within the queue, keeping track of the queues head, tail, number of elements as well as the maximum capacity of the queue. This class will also create an array which the queue will iterate through, the array is dynamically created by a value passed down into a function, if no value is present a default size queue of 10 will be made. All kind of dequeuing and enqueuing will take place within the class itself, a value will be passed down into the enqueue function and added to the actual queue as an element. No input or output is made within this class but its entirely reliant on pointers and references to allow other classes call the queues functions. 

The functions within the queue class will be called by another class which takes call of all the function calling, all input and output, simply put it acts as an UI. To tackle this I decided to use this class as a menu as well to make the program compact, in here the user have the option to create a queue of their specified size, add elements to the queue, remove elements from the queue, print the maximum amount of elements the queue can store, if the queue is full or empty, as well as print the current number of elements present in the queue. All those menu items are locked before a queue has been created, as there is no queue, there’s no reason for the user to be able to navigate the other options. Once a queue has been created the user can freely move between the menu options, if the user decide to create a new queue they can do so by simply choosing the corresponding menu option, this will in turn deallocate the previous queue as to not leak memory. 

To handle the blocking of certain menu options before a queue has been made I decided to use a simple bool option, only once a queue has been made will the other options open up. 


## Discussion
To start off this lab we were given the header contents of the queue class, as well as an example header for the test application. The headers simply described how the classes should look, no code was given to get us started in terms of function functionality. The queue itself is created within the queue class as an array, which the testapp program will in turn refer or point towards, the testapp is simply used to create an object to this queue.

I first had issues with getting the pointers and references to work, what I did was create an array and initialize it within the queue class which worked as it should, however I had created an object by calling the class in the testapp class, such as “Queue testQueue”. This obviously didn’t create a pointer to the queue itself but instead created an object of the class, what I wanted was a pointer to the object in the class. To achieve this I instead called the object as an unique ptr using the unique_ptr syntax and specifying the type as Queue, such as “unique_ptr<Queue>testQueue” which gave me the result I was after. Using this I could point towards the class and use the functions without actually creating a new instance, but simply by pointing towards the class and the variables stored within the object. 

The rest of the task was pretty straight forward, most of the functions in the queue class simply return a value to determine if the queue is full, empty, how many elements are stored within it, or what its maximum capacity is, to achieve this I simply compared the different variables to each other to achieve the result I was after. The testapp controlled all the input and the output of these functions, using pointers to call the queue functions. 

The enqueue and dequeue functions need to work a bit different, as we are using smart pointers and not raw pointers this was made a bit easier. To enqueue something the testapp class simply had to call the function in the queue class and send a valid value as parameter, which then gets added to the internal array. As this happens the tail need to increase by one, number of elements need to increase by one, dequeue works the same but opposite, as an element gets deleted the number of elements need to decrease by one, and head needs to increase by one. Deleting an element with smart pointers is very straight forward as the elements get deleted once they go out of scope, and they are out of scope as long as nothing is pointing towards them, which will never happen even if a full loop of the queue is made. If we were to use raw pointer instead we would have to assign a new nullptr value to the element we wish to delete, smart pointers don’t have this issue as they automatically delete the value once out of scope, hence why there are no leaks even if the code is void of any actual deletion. 

All in all this task was fun and taught me new things, at first glance it seemed like something we had already done but the smart pointers worked vastly different from anything we’ve done before, albeit easier it was new and took way less time to setup than raw pointers. We could use a lot of our previously created material to get the task going faster, such as previous menus. As it was a FIFO system we just had to store all the previous elements assigned and make sure the queue can’t overfill, as soon as a value gets deleted the first value ever entered will be the first one to go, and then the next, and the next, etc.

