//
// Created by Marcus Roos on 2020-10-10.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_MENU_H
#define DT060G_MENU_H

#include "MenuItem.h"
#include <vector>

//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Menu

 Handles the menus
 Contain members menuTitle as well as a vector of MenuItem to keep track of
 whether a menu is enabled or disabled, and what the name of said menu is.
 */
class Menu {
private:
    std::vector<MenuItem>menuItem;
    std::string menuTitle;
public:
    /**
* Default constructor of class Menu
*
* @param None.
* @return None.
*/
    Menu();

    /**
* Default destructor of class Menu
*
* @param None.
* @return None.
*/
    ~Menu()=default;

    /**
* Sets value for class member title
*
* @param string ptitle
* @return None.
*/
    void setTitle(std::string ptitle);

    /**
* Sets value of class member menuitems enabler to true
*
* @param None.
* @return None.
*/
    void setenableMenu();

    /**
* Returns value for class member menuTitle, constant
* Inline
* @param None.
* @return artist.
*/
    std::string getTitle() const { return menuTitle; }

    /**
* Prints elements stored in member menuItem, constant
*
* @param None.
* @return None.
*/
    void printMenuItems() const;

    /**
* Lets use choose their menu choice, validates their input before returning it
*
* @param None.
* @return Int.
*/
    int menuChoice();

    /**
* Adds an item to menuItem vector
*
* @param String and bool.
* @return None.
*/
    void addItem(const std::string &pmenuText, bool penabler);
};
#endif
