//
// Created by Marcus on 2020-03-14.
//

#ifndef DT019G_MANAGEMENT_H
#define DT019G_MANAGEMENT_H

#include <string>
#include <vector>
const std::string filename = "jukebox.txt";
void pauseFunction(const std::string& text);
std::string validate(std::string input);
std::string validateFileName(std::string input);
std::string lowercase(std::string input);
void printHeader();

#endif //DT019G_MANAGEMENT_H
