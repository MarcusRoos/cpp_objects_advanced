# Laboration 3
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
I decided it would be best to approach this just like the first part of the lab, 
by separating the account class from the rest of the program and 
isolate it together with a tester I could make sure the account class once again
worked as intended without any of the other parts interfering. I constructed 
a base class "Accounts", added all sorts of relevant functions to it, determined 
which I can inline define right away in the header file and which will be the same 
for all 3 account types. I then moved on to implement the 3 different account types,
and all functions which required to be redefined were made virtual, and 
those functions which couldn't be defined at all in the base class were made 
pure virtual and were defined later on in the different sub classes. 

When the different account types worked as specified by the requirements I had a few
dead functions which I could remove, such as "SetInterest", nowhere in the 
requirements were we supposed to implement a way to change the interest of 
an account, and the savings account had a 2% interest, and the long savings had 2% 
more interest than the savings account, so I simply had to implement it as such.
I could now move on to implement this new Account class to the full program and simply
adjust the other classes to comprehend and see the distinction between the 
three different account types, which mainly had to do with changing validations.

## Discussion
First off, I was a little bit unsure both how the interest is supposed to work, 
and if it should be possible to change it. From the lab specifications you 
should not be able to change the interest, which made this lab much easier. If 
there would be an option to change the interest I would incorporate it into the 
change credit part of the program and simply allow the user to 
select from a menu of (1, 2, 3) as options, 3 would exit and take them back
to the main menu, while 1 would increase interest by 1% and clicking 2 would 
decrease it by 1%. You would only be able to adjust the values of the savings 
account and not the long savings account, as you would change the interest values
of the saving account this would also invoke a need to re-adjust the interest for 
the long savings account. This would be done within the two different "SetInterest"
functions which I previously mentioned that I deleted, the set interest function
for the savings account would call to the LongSavingsAccount::SetInterest which 
would adjust its interest by the same amount, this is due to Long Savings Account
always having exactly 2% higher interest than the saving account.

Separating the classes and working on them in isolation made the whole 
programming experience much, much better. When I did the project in the previous
course I had to jump up and down the hierarchy, into different classes to
remedy the issues I had, and changing something in one class usually
meant I had to change something in another class (other than parameters 
and return values). When I worked on this assignment I could close-to forget about
classes such as Account or Customer when I had reached a certain point, and 
solely work in the UI, as I knew all the underlying classes worked as intended and 
and I had a clear insight on what types of parameters they needed and what values
would be returned. 

Assignment 3, different account types has its purpose for sure, but as it's the 
very first time I've used polymorphism it took much longer than it should. As 
I know the basics and how it actually works now it will be such a 
relief in the future when I'm dealing with very large classes and handling a 
lot of different functions, it's clear that the intention of polymorphism is to 
reduce the amount of work required while still being as efficient, or rather
more efficient than using different classes for everything.

I wasn't entire sure how the interest in regard to funds should work, nor how 
something would "reset annually", I read a thread about pulling time and date
using the ctime and chrono libraries to annually reset the withdrawal counter. 
This would mean I would have to store those values somewhere permanent, which
would be in the prsnnr.knt file, and later be read in when loading a file. While 
not a daunting task I decided to instead ignore those values 
when reading and writing files and using the programs exit as a form to 
reset the year. This both allowed for much easier testing and simulates the 
experience well enough, I also read a thread post on our miun forums regarding
pulling date and time not being required whatsoever so thats why I went 
with the approach that I did.

Regarding the interest rates I interpreted it either as; any funds being 
deposited to the account should be affected by the interest rates, i.e.
depositing 1000 to an account with an interest rate of 2% would instead
deposit 1020. Or it would be manipulated when printing account info and 
trying to withdraw funds, in which case the values returned and accepted 
would be manipulated by simply multiplying the accounts balance with 
the interest, i.e. having 35000 on an account with 4% interest would 
let the user withdraw 36400 instead of the usual 35000. Both solutions 
have the same result but different approaches and I decided to go
with the latter for unexplainable reasons, if it's wrong or if I've 
misinterpreted this part I'll happily either explain myself or change it 
as required. 

I feel like I have a somewhat basic understanding of polymorphism and pointers 
at this point, pointers is probably somewhat better than my understanding of 
polymorphism but it all comes with practice, and from what I can guess there will be 
a lot more of both in the final project. I really see the purpose of the polymorphism
and pointers and its actually something I enjoy fiddling with, there are a lot of 
opportunities to be made here, and it's not too hard once you get a basic 
understanding of it.