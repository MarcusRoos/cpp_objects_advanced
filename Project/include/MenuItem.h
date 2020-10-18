//
// Created by Marcus Roos on 2020-10-18.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_MENUITEM_H
#define DT060G_MENUITEM_H

#include <string>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class MenuItem

 Keeps track of whether a menu is enabled or not, as well as the text of menu.
 Contain members menutext of type string, and enabler of type bool.
 Member functions include constructor, destructor, get and set functions.
 */
class MenuItem {
private:
    std::string menutext;
    bool enabler;
public:
    /**
* Default constructor of class MenuItem
*
* @param None.
* @return None.
*/
    MenuItem();

    /**
* Constructor for initialization of class MenuItem
*
* @param string pmenutext and bool penabler
* @return None.
*/
    MenuItem(std::string pmenutext, bool penabler);

    /**
* Destructor of class MenuItem
*
* @param None.
* @return None.
*/
    ~MenuItem()=default;

    /**
* Sets value for class member enabler
*
* @param bool penabler
* @return None.
*/
    void setEnabled(bool penabler);

    /**
* Returns value for class member menutext, constant
* Inline
* @param None.
* @return menutext.
*/
    std::string getMenuText() const { return menutext;}

    /**
* Returns value for class member enabler, constant
* Inline
* @param None.
* @return enabler.
*/
    bool getEnabled() const { return enabler; }
};

#endif //DT060G_MENUITEM_H
