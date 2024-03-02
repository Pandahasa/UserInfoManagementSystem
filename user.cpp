/**
* Name: Prateek Panda
* Description: User class implementation that contains all user information required for program
* Date: <2/10/2024>
*/

#include "user.h"

User::User() {
    userID = 0;
    username = "NULL";
    password = "NULL";
}

User::User(int userID, string role, string username, string password, DateTime signIn, DateTime signOut, string firstName, string lastName,
           string address, string city, string state, string zipcode, string phoneNumber,
           string email) :
           Person(firstName, lastName, address, city, state, zipcode, phoneNumber, email) {

    this->loginDateTime = signIn;
    this->logoutDateTime = signOut;
    this->role = role;
    this->userID = userID;
    this->username = username;
    this->password = password;
}

User::~User()=default;

void User::setUserID(int userID) {
    this->userID = userID;
}

int User::getUserID() const {
    return userID;
}

void User::setRole(string role) {
    this->role = role;
}

string User::getRole() const {
    return role;
}

void User::setUsername(string username) {
    this->username = username;
}

string User::getUsername() const {
    return username;
}

void User::setPassword(string password) {
    this->password = password;
}

string User::getPassword() const {
    return password;
}

void User::setLoginDateTime(DateTime datetime) {
    loginDateTime = datetime;
}

DateTime User::getLoginDateTime() const {
    return loginDateTime;
}

void User::setLogoutDateTime(DateTime(datetime)) {
    logoutDateTime = datetime;
}

DateTime User::getLogoutDateTime() const {
    return logoutDateTime;
}

bool User::operator==(const User &rhs) const {
    return (this->getUserID() == rhs.getUserID());
}

bool User::operator!=(const User &rhs) const {
    return !(*this == rhs);
}

bool User::operator>(const User &rhs) const {
    return (this->getUserID() > rhs.getUserID());
}

bool User::operator<(const User &rhs) const {
    return (this->getUserID() < rhs.getUserID());
}

bool User::operator>=(const User &rhs) const {
    return (this->getUserID() >= rhs.getUserID());
}

bool User::operator<=(const User &rhs) const {
    return (this->getUserID() <= rhs.getUserID());
}

istream& operator>>(istream& in, User& user) {
    cout << "Enter UserID: ";
    in >> user.userID;
    return in;
}

ostream& operator<<(ostream& out, const User& user) {
    out << user.toString();
    return out;
}

string User::toString() const {
    stringstream ss;
    ss << userID << " " << username;
    return ss.str();
}


