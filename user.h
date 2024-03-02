/**
* Name: Prateek Panda
* Description: User class header which contains all information a user has
* Date: <2/10/2024>
*/

#define _CRT_SECURE_NO_WARNINGS  this should be used when using system time for professor to compile

#ifndef LAB1_MANAGEUSERACCS_USER_H
#define LAB1_MANAGEUSERACCS_USER_H

#include <string>
#include "datetime.h"
#include "person.h"

using namespace std;




class User : public Person {
public:
    friend istream& operator>>(istream& in, User& user);
    friend ostream& operator<<(ostream& out, User& user);
    /*
     * Default Constructor
     */
    User();
    /**
     * User constructor
     * @param userID UserID
     * @param role Role
     * @param username Username
     * @param password Password
     * @param firstName First Name
     * @param lastName Last Name
     * @param address Address
     * @param city City
     * @param state State
     * @param zipcode Zipcode
     * @param phoneNumber Phone Number
     * @param email Email
     */
    User(int userID, string role, string username, string password, DateTime signIn, DateTime signOut, string firstName,
         string lastName, string address, string city, string state,
         string zipcode, string phoneNumber, string email);
    /*
     * Default Destructor
     */
    ~User();

    //Getter and Setter Methods

    void setUserID(int userID);
    int getUserID() const;
    void setRole(string role);
    string getRole() const;
    void setUsername(string username);
    string getUsername() const;
    void setPassword(string password);
    string getPassword() const;
    void setLoginDateTime(DateTime datetime);
    DateTime getLoginDateTime() const;
    void setLogoutDateTime(DateTime datetime);
    DateTime getLogoutDateTime() const;

    //Operator overloading for User
    bool operator==(const User &rhs) const;
    bool operator!=(const User &rhs) const;
    bool operator>(const User &rhs) const;
    bool operator<(const User &rhs) const;
    bool operator>=(const User &rhs) const;
    bool operator<=(const User &rhs) const;

    string toString() const;

private:
    int userID;
    string role;
    string username;
    string password;
    DateTime loginDateTime;
    DateTime logoutDateTime;
};



#endif //LAB1_MANAGEUSERACCS_USER_H
