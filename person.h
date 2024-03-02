/**
* Name: Prateek Panda
* Description: Person class header that represents information of a person
* Date: <2/10/2024>
*/
#include <string>

using namespace std;

#ifndef LAB1_MANAGEUSERACCS_PERSON_H
#define LAB1_MANAGEUSERACCS_PERSON_H


class Person {
public:
    Person();
    /**
     *
     * @param firstName First Name
     * @param lastName Last Name
     * @param address Address
     * @param city City
     * @param state State
     * @param zipcode Zipcode
     * @param phoneNumber Phone Number
     * @param email Email
     */
    Person(string firstName, string lastName, string address, string city, string state,
           string zipcode, string phoneNumber, string email);
    /*
     * Default destructor
     */
    ~Person();

    //Getter and Setter Methods

    void setFirstName(string firstName);
    string getFirstName() const;
    void setLastName(string lastName);
    string getLastName() const;
    void setAddress(string address);
    string getAddress() const;
    void setCity(string city);
    string getCity() const;
    void setState(string state);
    string getState() const;
    void setZipcode(string zipcode);
    string getZipcode() const;
    void setPhoneNumber(string phoneNumber);
    string getPhoneNumber() const;
    void setEmail(string email);
    string getEmail() const;
private:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zipcode;
    string phoneNumber;
    string email;
};


#endif //LAB1_MANAGEUSERACCS_PERSON_H
