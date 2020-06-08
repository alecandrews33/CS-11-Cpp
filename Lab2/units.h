#include <iostream>
#include <vector>
#include <stdexcept>

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

// A class to keep track of all conversions we know how to perform
class UnitConverter {
    // Nested struct to keep track of conversion 3-tuples
    struct Conversion {
        string from_units;
        double multiplier;
        string to_units;
    };

    // A vector of Conversions
    vector<Conversion> conVec;

public:
    /* Try to add a Conversion to conVec. Throws invalid argument exception
     * if the conversion is already in the conVec.
     */
    void add_conversion(string from_units,
        double multiplier, string to_units);

    /* Converts from input UValue to the to_units, applying the multiplier to
     * the value. Throws an invalid argument exception if unable to perform
     * the conversion.
     */
    UValue convert_to(UValue input, string to_units);
};
