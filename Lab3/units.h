#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <set>

using namespace std;

// A united-value class
class UValue {
    // Represents numeric value of UValue
    double value;
    // Represents the units the value is in
    string units;

public:
    // Two argument Constructor
    UValue(double value, const string &units);

    // Accessors
    double get_value() const;
    string get_units() const;
};

UValue convert_to(const UValue &input, const string &to_units);

// A class to keep track of all conversions we know how to perform
class UnitConverter {
    // Nested struct to keep track of conversion 3-tuples
    struct Conversion {
        // The unit type this is converting from
        string from_units;
        // The multiplier that converts a value from from_units to to_units
        double multiplier;
        // The unit type this is converting to
        string to_units;
    };

    // A vector of Conversions
    vector<Conversion> conVec;

public:
    /* Try to add a Conversion to conVec. Throws invalid argument exception
     * if the conversion is already in the conVec.
     */
    void add_conversion(const string &from_units,
        const double &multiplier, const string &to_units);

    /*
     * Two argument conversion function that just calls the 3 argument function
     */
    UValue convert_to(const UValue &input, const string &to_units) const;

    /* Converts from input UValue to the to_units, applying the multiplier to
     * the value. Throws an invalid argument exception if unable to perform
     * the conversion.
     */
    UValue convert_to(const UValue &input, const string &to_units,
        set<string> seen) const;
};
