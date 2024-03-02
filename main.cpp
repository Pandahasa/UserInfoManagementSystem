/**
* Name: Prateek Panda
* Description: Main function that runs program
* Date: <2/10/2024>
*/
#include <iostream>
#include "user.h"
#include "datetime.h"
#include "menu.h"
#include "usermenu.h"

int main() {
    UserMenu *main_menu =  new UserMenu();
    main_menu->activate();

    //deallocate memory and set it to null
    delete main_menu;
    main_menu = nullptr;

    return 0;
}
