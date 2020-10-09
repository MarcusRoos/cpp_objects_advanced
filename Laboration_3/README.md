# Laboration 3

## Environment & Tools
Windows 10 64bit. 
IDE: CLion. 
Environment: MinGW 5.2 
CMake: mingw32 make 3.15.3 
C++ compiler: g++ 
Debugger: MinGW GDB 7.6.1 
Git: Git 2.23.0.windows.1

## Purpose
In this lab we've set out to learn more about the smart pointers, as well as 
polymorphism, the whole lab 3 were centered about polymorphism and getting
the classes to collaborate with each other, while it took more work this very first time, 
it's easy to notice it's simply there to save a lot of work from being done twice.

## Procedures
This lab started as lab 2, but we built onto it and ended up with lab 3 
as a result. Lab 2 wanted us to build the bare minimum for a bank to be up 
and running, we had a class to handle the different accounts for a single 
customer. To handle this single customer we had another class called Customer, or 
BankKund in my case, we also required another class simply called Bank which 
will handle all the function calling and point towards the 
actual customer. Those 3 aforementioned classes are all silent classes, meaning
no input or output is to be made, to take care of the input and output we 
added another class called "testAcc", all kind of output and input will be 
handled in this class. All the input will be handled in testapp, which will send 
those inputs to the bank class, the bank class will in turn send them to 
the BankKund class. The BankKund class will either process and use the input 
data for its own variables and functions, or send it to the account class, the 
account class can store 3 different accounts per 1 customer, and the bank
class can process 1 customer at any given moment.

To build this program I started by constructing the class at the bottom of the
hierarchy, the account class, as this class is only accessible and used by the 
BankKund class it made the most sense. A tester was made on the side to try out 
every new function added to the account class and make sure they work as intended, 
this is made and tested at such an early stage to ensure there's no interference 
which could tamper with the functions, if an error do arise with any of the 
accounts its bound to be in any of the other classes which will be higher up
in the hierarchy. 

The functions were added one by one, and tested one by one, once 
they all worked as intended I moved on to the BankKund class. I followed 
the same principle when adding this class, I added the functions one by one, and 
kept changing my tester function to accommodate for this new class, as the 
account class had already been tested thoroughly I could focus entirely 
on this new BankKund class, and if I had an error I knew it was in the BankKund
class and not the underlying account class. It worked out in my favor and 
the new functions were tested one by one, if a problem arose the problem were 
with the new class and it was much easier to pinpoint the issue and resolve it.

With the BankKund class added and working along with the Account class most of the 
fundamental functions of the program were in place. I added the Bank class here
to work as a function caller between the tester class and the BankKund class, as no
interaction had to be made with the Account class from any other class than the 
BankKund class it was easy to implement a bridge between the Bank and BankKund classes. 
I changed my tester function to work as a fullfledged UI with validators in place. 
At this point I had very few validators in place which could cause some ugly results, 
so those validators had to be put in place and made sure they were solid, with all 
this done the first part of the lab were done.

Come the next part of the request we set out to change the first class, the account
class, instead of having one simple account we changed it to contain three different
account types, one regular account "Transaction Account" which worked just like the 
previous single account type, two different types of savings accounts called 
"Savings Account" and "Long Savings Account", their names indicate their uses.

For this I reconstructed the Account class as a base class to support 3 
different subclasses, passed down by polymorphism. At first this seemed
like a daunting task, but once the unique features had been put in place it 
was no different from constructing 3 entirely new classes, except using 
polymorphism means less work and same results for me as a programmer.
Once again I decided

## Discussion