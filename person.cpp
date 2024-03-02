/**
* Name: Prateek Panda
* Description: Class implementation that represents information for a person
* Date: <2/10/2024>
*/

#include "person.h"

Person::Person() {
    this->firstName = "NULL";
    this->lastName = "NULL";
    this->address = "NULL";
    this->city = "NULL";
    this->state = "NULL";
    this->zipcode = "NULL";
    this->phoneNumber = "NULL";
    this->email = "NULL";
}

Person::Person(std::string firstName, std::string lastName, std::string address, std::string city, std::string state,
               std::string zipcode, std::string phoneNumber, std::string email) {

    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zipcode = zipcode;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

Person::~Person()=default;

void Person::setFirstName(string firstName) {
    this->firstName = firstName;
}

string Person::getFirstName() const {
    return firstName;
}

void Person::setLastName(string lastName) {
    this->lastName = lastName;
}

string Person::getLastName() const {
    return lastName;
}

void Person::setAddress(string address) {
    this->address = address;
}

string Person::getAddress() const {
    return address;
}

void Person::setCity(string city) {
    this->city = city;
}

string Person::getCity() const {
    return city;
}

void Person::setState(string state) {
    this->state = state;
}

string Person::getState() const {
    return state;
}

void Person::setZipcode(string zipcode) {
    this->zipcode = zipcode;
}

string Person::getZipcode() const {
    return zipcode;
}

void Person::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

string Person::getPhoneNumber() const {
    return phoneNumber;
}

void Person::setEmail(string email) {
    this->email = email;
}

string Person::getEmail() const {
    return email;
}