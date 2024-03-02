/**
* Name: Prateek Panda
* Description: Contains the user menu that will be used to do various actions
* Date: <2/10/2024>
*/

#include "usermenu.h"

UserMenu::UserMenu() {
    isSignedIn = false;
    addOption("Sign In");
    addOption("Sign Out");
    addOption("Reset Password");
    addOption("Create Account");
    addOption("Manage Profiles");

    initUserData();

}

UserMenu::~UserMenu()=default;

void UserMenu::activate() {
    int input = 0;
    //input is 6 then it runs exit() then activate ends which ends the program
    while (input != 6) {
        input = getInput();
        cout << "Input: " << input << endl;
        switch (input) {
            case USER_MENU_SIGNIN:
                isSignedIn = signIn();
                break;
            case USER_MENU_SIGNOUT:
                isSignedIn = signOut();
                break;
            case USER_MENU_RESET:
                reset();
                break;
            case USER_MENU_CREATE:
                create();
                break;
            case USER_MENU_MANAGE_PROFILE:
                manageProfiles();
                break;
            case USER_MENU_EXIT:
                exit();
                break;
        }
    }
}

bool UserMenu::signIn() {
    cout << "Enter your phone number/email/username" << endl;
    string login;
    cin >> login;
    cout << endl;
    cout << "Enter your password" << endl;
    string password;
    cin >> password;
    cout << endl;
    int count = 0;
    //-1 because it will be 0 on line 65
    userIndex = -1;
    do {
        //checks if username in users else informs user that username doesn't exist
        for (User user: users) {
            userIndex++;
            if (user.getUsername() == login || user.getEmail() == login || user.getPhoneNumber() == login) {
                while (true) {
                    //checks if password is valid else informs password is invalid
                    if (user.getPassword() == password) {
                        cout << "Sign in Successful!" << endl;
                        DateTime loginTime = getCurrentTime();
                        user.setLoginDateTime(loginTime);
                        //sets current user to this user
                        this->user = user;
                        updateUsersData();
                        return true;
                    } else {
                        count++;
                        if (count == 3) {
                            //if user has been wrong 3 times, then exits from sign in prompt
                            cout << "Too many incorrect attempts" << endl;
                            return false;
                        }
                        cout << "Incorrect Password" << endl;
                        cin >> password;
                    }
                }
            }
        }

        //only counts if username not in users
        count++;
        userIndex = -1; //resets the userIndex count as the users loop will rerun to find username
        if (count == 3) {
            //if user has been wrong 3 times, then exits from sign in prompt
            cout << "Too many incorrect attempts" << endl;
            return false;
        }
        cout << "Invalid Username" << endl;
        cin >> login;

    } while (true);
}

bool UserMenu::signOut() {
    //if the user is signed in, signs out or tells them they are not signed in the first place
    if (isSignedIn) {
        cout << "Successfully signed out" << endl;
        DateTime logoutTime = getCurrentTime();
        user.setLogoutDateTime(logoutTime);
        updateUsersData();
        return false;
    }
    else {
        cout << "Not signed in" << endl;
        return false;
    }
}

void UserMenu::create() {
    //checks if user is admin and prompts if they want to reset a user's password
    if (user.getRole() == "admin") {
        cout << "You are an admin, do you want to reset password of a user? yes/no" << endl;
        string response;
        cin >> response;
        if (response == "yes") {
            cout << "Which user's password would you like to change" << endl;
            string username;
            cin >> username;
            for (User &changeuser: users) { //must be & as to modify user or won't work
                if (changeuser.getUsername() == username) {
                    cout << "What password would you like to set " << username << " to?" << endl;
                    string newPassword;
                    cin >> newPassword;
                    changeuser.setPassword(newPassword);
                    cout << "Successfully changed" << endl;
                    updateUsersData();
                    return;
                }
            }
            cout << "That user was not found, please create an account instead" << endl;
        }
    }

    //getting all information for user
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    string email;
    string username;
    string password;
    //user should not use spaces unless address or program will stop reading at whitespace
    cout << "Enter first name" << endl;
    cin >> firstName;
    cout << "Enter last name" << endl;
    cin >> lastName;
    cin.ignore();
    cout << "Enter address" << endl;
    getline(cin, address);
    cout << "Enter city" << endl;
    cin >> city;
    cout << "Enter state" << endl;
    cin >> state;
    cout << "Enter zip" << endl;
    cin >> zip;
    cout << "Enter phone" << endl;
    cin >> phone;
    cout << "Enter email" << endl;
    cin >> email;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;
    cout << "Re-enter password" << endl;
    string tempPassword;
    cin >> tempPassword;
    while (tempPassword != password) {
        cout << "Does not match, re-enter password again" << endl;
        cin >> tempPassword;
    }
    cout << "What role would you like, guest/student/admin" << endl;
    string role;
    cin >> role;
    //creates a default DateTime and new userid for user
    int userID = 1001 + users.size();
    DateTime defaultDateTime = DateTime();
    User newUser = User(userID, role, username, password, defaultDateTime, defaultDateTime,
                        firstName, lastName, address, city, state, zip, phone, email);
    users.push_back(newUser);
    //PROGRAM MUST BE EXITED TO SAVE NEW USER
}

void UserMenu::reset() {
    //if the user is not signed in, tells them they are not signed in the first place
    if (!isSignedIn) {
        cout << "Not signed in" << endl;
        return;
    }
    else {
        cout << "Enter old password" << endl;
        string oldPassword;
        cin >> oldPassword;
        if (user.getPassword() == oldPassword) {
            cout << "Enter new password" << endl;
            string newPassword;
            cin >> newPassword;
            user.setPassword(newPassword);
            cout << "Successfully changed password" << endl;
        } else {
            cout << "Old password does not match" << endl;
        }
    }
    updateUsersData();
}

void UserMenu::manageProfiles() {
//if the user is not signed in, tells them they are not signed in the first place
    if (!isSignedIn) {
        cout << "Not signed in" << endl;
        return;
    }
    else {
        string choice;
        do {
            cout << "What would you like to update, firstname/lastname/address/city"
                    "/state/zipcode/phonenumber/email ?" << endl;
            cin >> choice;
            string change;
            if (choice == "firstname") {
                cout << "Enter the new first name: ";
                cin >> change;
                user.setFirstName(change);
            } else if (choice == "lastname") {
                cout << "Enter the new last name: ";
                cin >> change;
                user.setLastName(change);
            } else if (choice == "address") {
                cout << "Enter the new address: ";
                cin >> change;
                user.setAddress(change);
            } else if (choice == "city") {
                cout << "Enter the new city: ";
                cin >> change;
                user.setCity(change);
            } else if (choice == "state") {
                cout << "Enter the new state: ";
                cin >> change;
                user.setState(change);
            } else if (choice == "zipcode") {
                cout << "Enter the new zip code: ";
                cin >> change;
                user.setZipcode(change);
            } else if (choice == "phonenumber") {
                cout << "Enter the new phone number: ";
                cin >> change;
                user.setPhoneNumber(change);
            } else if (choice == "email") {
                cout << "Enter the new email: ";
                cin >> change;
                user.setEmail(change);
            } else {
                cout << "Invalid choice" << endl;
            }
            cout << "Would you like to change something else yes/no" << endl;
            cin >> choice;
        } while (choice == "yes");
    }
    updateUsersData();
}

void UserMenu::exit() {
    updateUsersData();
}

void UserMenu::initUserData() {
    string filename = "/Users/prateekp/CLionProjects/Mr.Pham CS124/Lab1-ManageUserAccs/users_data.csv";
    inFile.open(filename);

    if (!inFile) {// Returns error if file error occurs

        cout << "Error opening file: " << filename << std::endl;
        return;
    }

    string line;

    //all variables to pull from users_data.csv to make User objects
    string id;
    string role;
    string username;
    string password;
    string signInStr;
    string signOutStr;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    string email;

    DateTime signIn;
    DateTime signOut;

    //runs getline once to discard the header columns
    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);

        getline(ss, id, ',');
        int userID = stoi(id);
        getline(ss, role, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, signInStr, ',');
        getline(ss, signOutStr, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phone, ',');
        getline(ss, email, '\r');

        signIn = stringToDateTime(signInStr);
        signOut = stringToDateTime(signOutStr);

        users.push_back(User(userID, role, username, password, signIn, signOut, firstName, lastName, address, city,
                             state, zip, phone, email));
    }

    inFile.close();
}

DateTime UserMenu::stringToDateTime(string dateTime) {
    //DateTime variables
    stringstream ss(dateTime);
    string temp;
    int day;
    int month;
    int year;
    int second;
    int minute;
    int hour;

    getline(ss, temp, '/');
    day = stoi(temp);
    getline(ss, temp, '/');
    month = stoi(temp);
    getline(ss, temp, ' ');
    year = stoi(temp);
    getline(ss, temp, ':');
    hour = stoi(temp);
    getline(ss, temp, ':');
    minute = stoi(temp);
    getline(ss, temp);
    second = stoi(temp);
    return DateTime(month, day, year, hour, minute, second);
}

DateTime UserMenu::getCurrentTime() {
    time_t t = time(0);    // get time now
    tm* now = localtime(&t);
    int mo;
    int d;
    int yr;
    int hr;
    int min;
    int sec;

    mo = now->tm_mon + 1;
    d = now->tm_mday;
    yr = now->tm_year + 1900;

    hr = now->tm_hour;
    min = now->tm_min;
    sec = now->tm_sec;
    DateTime temp = DateTime(mo, d, yr, hr, min, sec);
    return temp;
}

void UserMenu::updateUsersData() {
    if (isSignedIn) {
        users[userIndex] = user;
    }
    string filename = "/Users/prateekp/CLionProjects/Mr.Pham CS124/Lab1-ManageUserAccs/users_data.csv";
    inFile.open(filename, ios::out | ios::trunc);

    if (!inFile) {// Returns error if file error occurs

        cout << "Error opening file: " << filename << std::endl;
        return;
    }

    inFile << "Id,Role,Username,Password,Sign-in datetime,Sign out datetime"
              ",First Name,Last Name,Address,City,State,Zip,Phone,Email\n";

    stringstream line;
    for (User user: users) {
        line << user.getUserID() << "," << user.getRole() << "," << user.getUsername() << ","
        << user.getPassword() << "," << user.getLoginDateTime().toString() << "," << user.getLogoutDateTime().toString()
        << "," << user.getFirstName() << "," << user.getLastName() << "," << user.getAddress() << ","
        << user.getCity() << "," << user.getState() << "," << user.getZipcode() << "," << user.getPhoneNumber()
        << "," << user.getEmail() << "\n";
    }

    inFile << line.str();

    inFile.close();
}