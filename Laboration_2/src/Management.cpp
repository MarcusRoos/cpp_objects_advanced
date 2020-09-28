//
// Created by Marcus on 2020-03-14.
//
#include <limits>
#include <iostream>
#include <algorithm>
#include "Management.h"
using namespace std;

void pauseFunction(const std::string& text){ /* Function used when program
 * should wait for user input before it continues */
    std::cout << text; // Prints function parameter on screen
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.get(); // Waits for user input before it continues
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
}

std::string validate(std::string input){ // Validate input
    bool valid;
    do {
        std::getline(std::cin >> std::ws, input);
        valid = true;
        for (std::size_t i{}; i < input.length() && valid; ++i) { /*Iterates
 * through inputs length, checks if input is either a letter or a space,
 * anything else is considered invalid*/
            if (!(std::isalpha(static_cast<unsigned char>(input[i])) ||
                  std::isspace(static_cast<unsigned char>(input[i])))) {
                valid = false;
                std::cout << "Invalid input\n";
            }
        }
    } while (!valid);
    return input;
}

std::string validateFileName(std::string input){ // Validate input
    bool valid;
    do {
        valid = true;
        std::getline(std::cin >> std::ws, input);
        if (input=="COM1" || input=="COM2" || input=="COM3" || input=="COM4"
            || input=="COM5" || input=="COM6" || input=="COM7" || input=="COM8"
            || input=="COM9" ||input=="LPT1" || input=="LPT2" || input=="LPT3"
            || input=="LPT4" || input=="LPT5" || input=="LPT6" || input=="LPT7"
            || input=="LPT8" || input=="LPT9" || input=="CON" || input=="PRN"
            || input=="AUX" || input=="NUL"){ // Reserved file names
            valid = false;
            std::cout << "Invalid input\n";
        }
        for (std::size_t i{}; i < input.length() && valid; ++i) { /*Iterates
 * through inputs length, checks if input is valid, will not accept follow
 * characters due to being forbidden in both windows and unix systems.*/
            if (input[i]=='<' || input[i]=='>' || input[i]=='"' || input[i]=='/'
                || input[i]=='\\' || input[i]=='*' || input[i]==':' || input[i]=='?'
                || input[i]=='|') { // Forbidden characters
                valid = false;
                std::cout << "Invalid input\n";
            }
        }
    } while (!valid);
    return input;
}

std::string lowercase(std::string input){
    std::for_each(input.begin(), input.end(),
                  [](char &c) {
                      c = tolower(c);
                  });
    return input;
}

void printHeader(){
    std::cout << "No.  Title                                                  "
                 "Artist         Length\n";
    std::cout << "==========================================================="
                 "======================\n";
}