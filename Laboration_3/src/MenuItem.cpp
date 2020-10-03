//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "MenuItem.h"
#include <utility>

// Default constructor
MenuItem::MenuItem() {
    menutext = "";
    enabler = false;
}

// Initilizing constructor
MenuItem::MenuItem(std::string pmenutext, bool penabler) {
    menutext = std::move(pmenutext);
    enabler = penabler;
}

// Sets enabler
void MenuItem::setEnabled(bool penabler) {
    enabler = penabler;
}


