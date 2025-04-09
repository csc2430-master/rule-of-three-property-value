#include <iostream>
#include <string>

#include "property.h"

using std::cout;
using std::endl;
using std::string;

bool CompareColor(Property properties, const string& color, const string& name);

int main(int argc, const char * argv[]) {

      Property prop(4);
      cout << (prop.SetProperty("red", "#FF0000") ? "Inserted" : "Not Inserted") << endl;
      cout << (prop.SetProperty("green", "#FFFF00") ? "Inserted" : "Not Inserted") << endl;
      cout << (prop.SetProperty("blue", "#0000FF") ? "Inserted" : "Not Inserted") << endl;
      cout << (prop.SetProperty("green", "#00FF00") ? "Inserted" : "Not Inserted") << endl;
      cout << (prop.SetProperty("white", "#FFFFFF") ? "Inserted" : "Not Inserted") << endl;
      cout << (prop.SetProperty("black", "#000000") ? "Inserted" : "Not Inserted") << endl;

      cout << prop.GetProperty("red") << endl;
      cout << prop.GetProperty("green") << endl;
      cout << prop.GetProperty("blue") << endl;
      cout << prop.GetProperty("white") << endl;
      cout << prop.GetProperty("black") << endl;

      if (CompareColor(prop, "red", "#FF0000")) {
            cout << "Red is Yes" << endl;
      }else {
            cout << "Red is No" << endl;
      }
      if (CompareColor(prop, "blue", "#FF0000")) {
            cout << "Blue is Yes" << endl;
      }else{
            cout << "Blue is No" << endl;
      }

      Property other(4);
      other = prop;
      cout << other.GetProperty("red") << endl;
      cout << other.GetProperty("green") << endl;
      cout << other.GetProperty("blue") << endl;
      cout << other.GetProperty("white") << endl;
      cout << other.GetProperty("black") << endl;


      return 0;
}

bool CompareColor(Property properties, const string& name, const string& color){
      if (properties.GetProperty(name) == color)
            return true;
      else
            return false;
}