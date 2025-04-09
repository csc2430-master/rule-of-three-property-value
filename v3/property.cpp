//
// Created by Arias Arevalo, Carlos on 4/9/25.
//

#include "property.h"

Property::Property(unsigned int capacity): _capacity(capacity) {
    _names = new string[_capacity];
    _values = new string[_capacity];
    _size = 0;
}
Property::Property(const Property &other): _capacity(other._capacity), _size(other._size) {
  _names = new string[_capacity];
  _values = new string[_capacity];
  for (unsigned int i = 0; i < _size; i++) {
    _names[i] = other._names[i];
    _values[i] = other._values[i];
  }
}
Property::~Property() {
  delete[] _names;
  delete[] _values;
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
