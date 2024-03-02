/**
* Name: Prateek Panda
* Description: User menu class header which does the primary actions of the program
* Date: <2/10/2024>
*/

#define _CRT_SECURE_NO_WARNINGS  this should be used when using system time for professor to compile

#ifndef LAB1_MANAGEUSERACCS_USERMENU_H
#define LAB1_MANAGEUSERACCS_USERMENU_H

#include <fstream>
#include <sstream>
#include "menu.h"

enum USER_MENU_OPTION {
    USER_MENU_SIGNIN = 1,
    USER_MENU_SIGNOUT = 2,
    USER_MENU_RESET = 3,
    USER_MENU_CREATE = 4,
    USER_MENU_MANAGE_PROFILE = 5,
    USER_MENU_EXIT = 6
};


class UserMenu : public Menu {
public:
    /*
     * Default Constructor
     */
    UserMenu();
    /*
     * Default Destructor
     */
    ~UserMenu();
    /*
     * Activates the Menu and prints options to Console
     */
    void activate();

private:
    //Menu Member Actions
    bool signIn();
    bool signOut();
    void reset();
    void create();
    void manageProfiles();
    void exit();

    //Converts datetime string from csv to a DateTime object
    DateTime stringToDateTime(string dateTime);

    //gets current time and makes into DateTime object
    DateTime getCurrentTime();

    //updates csv file with new information
    void updateUsersData();

    fstream inFile;
    User user;
    vector<User> users;
    void initUserData(); //reads user data to populate the users vector
    bool isSignedIn;
    int userIndex;
};


#endif //LAB1_MANAGEUSERACCS_USERMENU_H
