/**
* Title:      A properties class
*
* Purpose:    A Class to represent a list of pairs (Key, Value)
* Topics:     Rule of three, dynamic memory allocation and deallocation, memory leaks
* Author:     Carlos R. Arias
* Date:       2025-04-10
*/

#include "property.h"

/**
* This is the constructor, creates the arrays according to the capacity and
* @param capacity it is the user defined capacity of the container
*/

Property::Property(unsigned int capacity): _capacity(capacity) {
    _names = new string[_capacity];
    _values = new string[_capacity];
    _size = 0;
}
/**
* Copy constructor
* Necessary because we are using dynamic memory. It is going to be called
* explicitly when the user instantiates a Property with another property
* as parameter, or when we ask for copies, for instance with parameters
* or returns by value. Note that this constructor does a DEEP copy!
* @param other the original Property to copy.
*/
Property::Property(const Property &other): _capacity(other._capacity), _size(other._size) {
  _names = new string[_capacity];
  _values = new string[_capacity];
  for (unsigned int i = 0; i < _size; i++) {
    _names[i] = other._names[i];
    _values[i] = other._values[i];
  }
}

/**
* Copy assignment operator, operator = overload.
* This method will be called when an assignment between two instances of Property are
* used in an assignment: prop1 = prop2. This will always be the LHS and other represents
* the RHS. It is necessary to provide this method because the class uses dymamic memory.
* @param other represents the RHS of the assignment
* @return this
*/
Property& Property::operator=(const Property &other) {
  if (this != &other) {
    // Aca o alla
    _capacity = other._capacity;
    _size = other._size;
    _names = new string[_capacity];
    _values = new string[_capacity];
    for (unsigned int i = 0; i < _size; i++) {
      _names[i] = other._names[i];
      _values[i] = other._values[i];
    }
  }
  return *this;
}
/**
* Destructor of the class.
* Required because the class uses dynamic memory. This destructor will
* deallocate the memory allocated by the constructors.
*/
Property::~Property() {
  delete[] _names;
  delete[] _values;
}
/**
* Associates the name (key) with a given value.
* This method
* a. Will check if the name is already there. If so, it will update the value.
* b. Will check if the new name fits in the array, if so it will insert it at the last position.
* c. If the add operation is successful it will return true, false otherwise.
* @param name the name to be associated with the value
* @param value the value to be associate with the name
* @return true when the adding operation is successful, either the name was there and was updated
               or it was not there, and therefore added. False otherwise.
*/
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
/**
* Retrieves a property with a given name.
* Does a linear search over the array _names to search for the name in the parameter.
* If the name is found, then it will return the corresponding value. If it is not found
* it will return the empty string. Note that perhaps it would be best to return a pointer
* so nullptr can be specified for "not found" since it could be that the empty string is a
* valid value.
* @param name the name to search for
* @return the value associated with the name if the name is found, empty string otherwise.
*/
string Property::GetProperty(string name) const {
    for (unsigned int i = 0; i < _size; i++) {
        if (_names[i] == name) {
            return _values[i];
        }
    }
    return "";
}
