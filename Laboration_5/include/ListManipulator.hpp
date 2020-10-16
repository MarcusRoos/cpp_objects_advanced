//
// Created by Marcus Roos on 2020-10-14.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_LISTMANIPULATOR_HPP
#define DT060G_LISTMANIPULATOR_HPP
#include <list>
#include <random>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <ctime>
#include <typeinfo>
#include <cstring>

/**
 Class ListManipulator

This class handles a list of type T, user-defined at runtime. The ListManipulator
 class will manipulate the list in several different ways, from behind able to
 populate the list with 20 values, printing out the sum of all the values,
 sorting the list, dividing by two, clearing the list, reading and writing
 from/to file. Each individual manipulator will be described below.
 */

template<typename T>
class ListManipulator{
private:
    //Declares a pointer to a list of type T
    std::list<T> *theList;
public:
    //Function declarations below, declares every function with relevant
    //return and/or parameter type
    ListManipulator(std::list<T> *aList);
    ~ListManipulator(){};
    void fillList();
    void sumList() const;
    void listAverage() const;
    bool findFirst1500_1900(T &num) const;
    void DivideByTwo();
    void swapPlaces();
    void findMinMax(T &min, T &max) const;
    void sortList();
    void clearList();
    void getList() const;
    void saveToFile() const;
    void readFromFile();
};

/** Constructor for the class ListManipulator, will initialize theList
 * with passed down parameter.
 * **/
template<typename T>
ListManipulator<T>::ListManipulator(std::list<T> *aList) {
    theList = aList;
}

/** This function will fill theList, with 20 different numbers, at first it will
 * clear the list to remove any residue from previous initializations, and to
 * avoid being able to store more than 20 values the list is resized to that
 * of 20. As the function should be able to populate the list with either integer
 * or doubles as determined by user at runtime I decided to solve it by
 * using a random number generator which will generate doubles and push
 * those to the list. If the user chose to use doubles it will proceed
 * as expected, but if the user chose integers at the start, the values pushed
 * will instead be rounded to their nearest integer and stored as such.
 * I used a lambda function instead of a separate one as to save code space
 * when writing the generate.
 * **/
template<typename T>
void ListManipulator<T>::fillList() {
    theList->clear();
    theList->resize(20);
    static std::default_random_engine rng(unsigned(time(0)));
    std::uniform_real_distribution<double> distribution(1000, 2000);
    std::generate(theList->begin(), theList->end(), [&]{
        T number = distribution(rng);
        return number;
    });
}

/** This function will make use of standard library function "accumulate" to
 * calculate the sum of all values in the list, it accomplishes this by iterating
 * from the start of the list to the end of the list and adding the value
 * at each iterators position to a grand total. This value is then
 * printed.
 * **/
template<typename T>
void ListManipulator<T>::sumList() const {
   std::cout << "Summary: " <<std::accumulate(theList->begin(), theList->end(),
           0.0) << std::endl;
}

/** This function will make use of standard library function "accumulate" to
 * calculate the sum of all values in the list and then calculate the average
 * size of each value. It accomplishes this by iterating
 * from the start of the list to the end of the list and adding the value
 * at each iterators position to a grand total. It then divides the total by
 * the size of the list to get an average size of every value. This
 * value is then printed for the user to see.
 * **/
template<typename T>
void ListManipulator<T>::listAverage() const {
    T avg=0;
    avg = std::accumulate(theList->begin(), theList->end(), 0.0);
    avg = avg/theList->size();
    std::cout << "Average: " << avg << std::endl;
}

/** This function is supposed to find the first value in the interval
 * 1500-1900, it does this by iterating through the list and returning
 * true once it manages to find a value within the interval. I added
 * a bit more comprehensive text section below as reasoning to my
 * implementation as well as an alternative method if I missunderstood
 * the assignment.
 * **/
template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &num) const {
    /*I wasn't entirely sure if we were meant to find the first number
 * between 1500-1900 as in the lowest number in this interval, or simply
 * the first one in an unsorted list (i.e. 1678 at #1 in the list but
 * 1675 at #3 would return 1678 as its the first value "found".
 * If that was the plan, simply remove everything the comments below, and add
     * comments to the active code.*/
/**         //  Inactive code
    auto it = find_if(theList->begin(), theList->end(), [](T a) {
        return a >= 1500 && a <=1900;
    });
    if (it != theList->end()){
        num = *it;
        std::cout <<"Smallest value between 1500 and 1900 = " <<num << std::endl;
        return true;
    }
    else
        return false;
    **/

    std::list<T> tmpList;
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++) {
        tmpList.push_back(*it);
    }
    tmpList.sort();
    auto it = find_if(tmpList.begin(), tmpList.end(), [](T a) {
        return a >= 1500 && a <=1900;
    });
    if (it != tmpList.end()){
        num = *it;
        std::cout <<"Smallest value between 1500 and 1900 = " <<num << std::endl;
        return true;
    }
    else
    return false;

}

/** This function is meant to divide each and every value by 2, essentially
 * halving the original value. To achieve this I used the "transform" function
 * from the standard library. It will iterate through theList from begin()
 * to end() and manipulate each value stored at each location, those new
 * values will then be stored in a container at specified slot, in my
 * case, thats back at the start of theList (theList->begin()).
 * It will then use another function called bind and its algorithm "divides",
 * it will pull in one value at a time and store it at the "placeholders::_1"
 * position, then it will divide it by 2 as determined by the '2' towards the
 * end of the function. Once the division is done the value will be
 * added back to theList.
 * **/
template<typename T>
void ListManipulator<T>::DivideByTwo() {
    std::transform(theList->begin(), theList->end(), theList->begin(),
            std::bind(std::divides<T>(),std::placeholders::_1, 2));
}

/** This function swaps the places of the 1st and 20th value in theList, then
 * the 2nd and 19th value, 3rd and 18th value and so on, until it reaches
 * the middle. To achieve this I created a new, dummy list iterator of
 * type T, assigned them the name fIt and bIt (front iterator, back iterator),
 * I decreased the backiterator by one before even proceeding as it always points
 * right outside the list so any swapped values wouldve been placed outside the
 * list, essentially being gone.
 * I used the iter_swap function from the standard library to achieve this,
 * and my previously created iterators to keep track of which values should
 * swap place, I let it iterate for half of theLists size as I only wanted to
 * swap the places of every value once, I can safely stop once both iterators
 * meet in the middle.
 * **/
template<typename T>
void ListManipulator<T>::swapPlaces() {
    std::_List_iterator<T> fIt=theList->begin(), bIt=theList->end();
    bIt--;
    for (size_t i=0; i<theList->size()/2; i++) {
        std::iter_swap(fIt, bIt);
        fIt++;
        bIt--;
    }
}

/** This function will use the standrad libraries min_element and max_element
 * to help me find the biggest as well as smallest value in the list.
 * I simply call this function by letting two dummy variables pass down
 * as parameters of type T, those values will be referencing to the
 * min and max values found in the function and print them on the screen.
 * It achieves this by iterating through theList from beginning to end and storing
 * the biggest, and smallest value in the respective function call.
 * **/
template<typename T>
void ListManipulator<T>::findMinMax(T &min, T &max) const {
    min = *std::min_element(theList->begin(), theList->end());
    max = *std::max_element(theList->begin(), theList->end());
    std::cout <<"Min: " <<min << std::endl;
    std::cout <<"Max: " <<max << std::endl;
}

/** Sorts the list in ascending order, no parameter required as the sort
 * function without parameters will sort any container ascending by default.
 * **/
template<typename T>
void ListManipulator<T>::sortList() {
    theList->sort();
    std::cout << "List sorted." << std::endl;
}

/** Clears the list by using clear(), will empty memory to assure there's no
 * memory leaks.
 * **/
template<typename T>
void ListManipulator<T>::clearList() {
    theList->clear();
    std::cout << "List cleared." << std::endl;
}

/** Prints out the list on the screen for the user to see, iterates through the
 * entire list and prints the value stored at each iterator.
 * **/
template<typename T>
void ListManipulator<T>::getList() const {
    auto start = theList->begin(), stop = theList->end();
    for (auto it = start; it != stop; it++)
        std::cout << (*it) << std::endl;
}

/** Saves the list to a file, file name is determined by the typename,
 * if the user chose "double" at the start of the program the name of the
 * file will be list_double.dat, if the user instead chose integer the
 * file will be called list_integer.dat. It will open an outstream to
 * fs, and once the type has been determined it will open a file with the
 * relevant name. Prints each line to the file by using the copy function from
 * the standard library, iterating through the list and printing each value.
 * Once eof has been reached the outstream will close.
 * **/
template<typename T>
void ListManipulator<T>::saveToFile() const {
    std::ofstream fs;
    const std::type_info& ti1 = typeid(T);
    if (strncmp (ti1.name(),"i", 1) == 0){
        fs.open("list_integer.dat");
    }
    if (strncmp (ti1.name(),"d", 1) == 0){
        fs.open("list_double.dat");
    }
    std::copy(theList->begin(), theList->end(), std::ostream_iterator<T>(fs, "\n"));
    fs << "\n";
    fs.close();
    std::cout << "Saved." << std::endl;
}

/** Same concept as the saveToFile() function, if the user chose integer at the
 * start the function will attempt to open a file named list_integer.dat
 * and list_double.dat if the user chose a double. It will open the file and open
 * an instream, using copy and back_inserter to insert the values in order
 * into theList. Once done and eof has been reached it will close the instream.
 * **/
template<typename T>
void ListManipulator<T>::readFromFile() {
    std::ifstream inFile;
    const std::type_info& ti1 = typeid(T);
    if (strncmp (ti1.name(),"i", 1) == 0){
        inFile.open("list_integer.dat");
    }
    if (strncmp (ti1.name(),"d", 1) == 0){
        inFile.open("list_double.dat");
    }
    if(!inFile.is_open()){
        std::cout << "Could not locate any file of loaded type."
                     " \nPlease create a list first with "
                     "your currently loaded type, then proceed"
                     " to save it." << std::endl;
    }
    else {
        std::istream_iterator<T> tmpIt;
        std::istream_iterator<T> in(inFile);
        std::copy(in, tmpIt, std::back_inserter(*theList));
    }
    inFile.close();

}

#endif //DT060G_LISTMANIPULATOR_HPP