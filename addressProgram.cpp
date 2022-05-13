// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04s//22
// Description: gets input from a user, will return their address in the canada
// post format
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::transform;
using std::toupper;


// This function is used to convert each character to uppercase
string capStr(string s) {
    // transdorm is a built in function with the algorithm library
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
    return s;
}

// this is the function that takes the inputted information and
// formats it to comply with the Canada post rules. sets apartment with a
// default set at ""
string formatAddress(string name, string streetNum, string streetName,
    string city, string province, string postal, string apartment = "") {
    char ch1, ch2, ch3;
    string upLine1, upLine2, upLine3, upper, line1, line2, line3;
    // chooses which strings to concatonate
    if (apartment != "") {
        line1 = name;
        line2 = apartment + "-" + streetNum + " " + streetName;
        line3 = city + " " + province + " " + postal;
    } else {
        line1 = name;
        line2 = streetNum + " " + streetName;
        line3 = city + " " + province + " " + postal;
    }

    // calls the capStr function for each string to capitalize
    upLine1 = capStr(line1);
    upLine2 = capStr(line2);
    upLine3 = capStr(line3);
    // concatenates to one final string to return to main
    upper = upLine1 + "\n" + upLine2 + "\n" + upLine3;

    return upper;
}


int main() {
    // getting all of the users postal information
    string name, answer, apartment, streetNum, address;
    string streetName, city, province, postal;
    cout << "Enter your name: ";
    std::getline(cin >> std::ws, name);
    cout << "Do you live in an apartment? (y/n): ";
    std::getline(cin >> std::ws, answer);
    if (answer == "y") {
        cout << "Enter the apartment number: ";
        std::getline(cin >> std::ws, apartment);
    }
    cout << "Enter your street number: ";
    std::getline(cin >> std::ws, streetNum);
    cout << "Enter the street name AND classification: ";
    std::getline(cin >> std::ws, streetName);
    cout << "Enter your city: ";
    std::getline(cin >> std::ws, city);
    cout << "Enter your province's abbreviation: ";
    std::getline(cin >> std::ws, province);
    cout << "Enter your postal code: ";
    std::getline(cin >> std::ws, postal);

    // chooses whether or not to call the formatting function with the apartment
    if (answer == "y") {
        address = formatAddress(name, streetNum,
        streetName, city, province, postal, apartment);
    } else {
        address = formatAddress(name, streetNum, streetName,
        city, province, postal);
    }
    // displays result
    cout << endl << endl << address;
}
