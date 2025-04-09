//
// Created by Arias Arevalo, Carlos on 4/9/25.
//

#include "property.h"

Property::Property(unsigned int capacity): _capacity(capacity) {
    _names = new string[_capacity];
    _values = new string[_capacity];
    _size = 0;
}

bool Property::SetProperty(string name, string value) {
    bool success = false;
    for (unsigned int i = 0; i < _size; i++) {
        if (_names[i] == name) {
            _values[i] = value;
            success = true;
        }
    }
    if (success)
        return true;
    if (_size >= _capacity) {
        return false;
    }
    _names[_size] = name;
    _values[_size] = value;
    _size++;
    return true;
}

string Property::GetProperty(string name) const {
    for (unsigned int i = 0; i < _size; i++) {
        if (_names[i] == name) {
            return _values[i];
        }
    }
    return "";
}
