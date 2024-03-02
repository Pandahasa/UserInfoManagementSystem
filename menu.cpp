/**
* Name: Prateek Panda
* Description: Base menu class that used to display menu options
* Date: <2/10/2024>
*/

#include "menu.h"

Menu::Menu() {
}

Menu::~Menu()=default;

void Menu::addOption(std::string optionName) {
    options.push_back(optionName);
}

int Menu::getInput() const {
    string input;
    int intInput;
    do {
        display();
        cin >> input;
        if (input == "x") {input = "6";}
        intInput = stoi(input);
    } while (intInput <= 0 || intInput > options.size() + 1);
    return intInput;
}

void Menu::display() const {
    int count;
    cout << "***** ***** ***** *****" << endl;
    for (string option: options) {
        cout << count << ") " << option << endl;
        count++;
    }
    cout << "x" << ") " << "Quit" << endl;
}