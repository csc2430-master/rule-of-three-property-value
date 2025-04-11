/**
* Title:      A properties class
*
* Purpose:    A Class to represent a list of pairs (Key, Value)
* Topics:     Rule of three, dynamic memory allocation and deallocation, memory leaks
* Author:     Carlos R. Arias
* Date:       2025-04-10
*/

#ifndef PROPERTY_H
#define PROPERTY_H


#include <string>
using std::string;

class Property {
    string* _names;                // Dynamically allocated array of strings to store keys
    string* _values;               // Dynamically allocated array of strings to store the values
                                   // These two arrays are parallel, so _names[0] is the key for _values[0]
    unsigned int _capacity;        // Represents the maximum number of elements these structure can hold
    unsigned int _size;            // Represents the current number of elements the structure is holding
public:
    Property(unsigned int size);
    Property(const Property& other);
    Property& operator=(const Property& other);
    ~Property();
    bool SetProperty(string name, string value);
    string GetProperty(string name)const;

};



#endif //PROPERTY_H
