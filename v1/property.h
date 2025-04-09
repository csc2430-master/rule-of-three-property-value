//
// Created by Arias Arevalo, Carlos on 4/9/25.
//

#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
using std::string;

class Property {
    string* _names;
    string* _values;
    unsigned int _capacity;
    unsigned int _size;
public:
    Property(unsigned int size);
    bool SetProperty(string name, string value);
    string GetProperty(string name)const;
};



#endif //PROPERTY_H
