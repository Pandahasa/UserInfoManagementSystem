/**
* Name: Prateek Panda
* Description: Base menu class header which outputs options as required
* Date: <2/10/2024>
*/

#include "user.h"

#ifndef LAB1_MANAGEUSERACCS_MENU_H
#define LAB1_MANAGEUSERACCS_MENU_H


/*
 * Menu to display to console
 */
class Menu {
public:
    /**
     * Default constructor for Menu
     */
    Menu();
    /**
     * Destructor for menu
     */
    ~Menu();
    /**
     * Adds new option to print to console
     * @param optionName Name of option to print
     */
    void addOption(string optionName);
    /**
     * Displays the menu and asks for an input until valid input produced
     * @return Input produced by user
     */
    int getInput() const;
private:
    void display() const;
    vector<string> options;
};


#endif //LAB1_MANAGEUSERACCS_MENU_H
