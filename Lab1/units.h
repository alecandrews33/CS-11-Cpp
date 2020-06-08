#include <iostream>

using namespace std;

// A united-value class
class UValue {
    // Represents numeric value of UValue
    double value;
    // Represents the units the value is in
    string units;

public:
    // Two argument Constructor
    UValue(double value, string units);

    // Destructor
    ~UValue();

    // Accessors
    double get_value();
    string get_units();
};

UValue convert_to(UValue input, string to_units);
