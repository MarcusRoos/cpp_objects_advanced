//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Menu.h"
#include <iostream>
#include <utility>
#include <limits>

// Default constructor for class Menu
Menu::Menu() {
    menuTitle="";
}

// Sets title
void Menu::setTitle(std::string ptitle) {
    menuTitle = std::move(ptitle);
}

// Add item to vector of type menuItem
void Menu::addItem(const std::string& pmenuText, bool penabler) {
   menuItem.emplace_back(pmenuText, penabler);
}

// Prints menu
void Menu::printMenuItems() const {
    using namespace std;
    int i = 0;
    string title;
    title = getTitle();
    cout << title << endl;
    for (const auto& e : menuItem){
        i++;
        cout << i << ".  " << e.getMenuText() << "\n";
    }
}

// Allows user input to choose a menu option
int Menu::menuChoice() {
    using namespace std;
    int choice=0;
    cout << "Choice...";
    cin >> choice;
    while (std::cin.fail() || choice <1 || choice >14){
        std::cout << "Wrong input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    if (!menuItem[choice-1].getEnabled())
        cout << "Menu currently disabled\n";

    if (menuItem[choice-1].getEnabled())
    return choice;
    else
        return 0;
}

// Flicks a switch enabling all the previously disabled menus
void Menu::setenableMenu() {
    for (auto &e : menuItem)
        e.setEnabled(true);
}
