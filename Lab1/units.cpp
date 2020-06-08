#include "units.h"

// Two argument constructor for UValue class. Takes in a value and units.
UValue::UValue(double value, string units) {
    this->value = value;
    this->units = units;
}

// Cleans up a UValue object.
UValue::~UValue() {
    // No dynamically allocated resources; nothing to do here
}

// Returns the value (double) of the object. No inputs.
double UValue::get_value() {
    return this->value;
}

// Returns the units (string) of the object. No inputs.
string UValue::get_units() {
    return this->units;
}

/* Tries to convert from one UValue to the units specified
 * by the to_units string. Returns input UValue if unable to
 * convert. Input is a UValue and a string for destination units.
 * Output is a UValue.
 */
UValue convert_to(UValue input, string to_units) {
    double val = input.get_value();
    if (input.get_units() == "lb" && to_units == "kg") {
        UValue result{val * 0.45, to_units};
        return result;
    }
    if (input.get_units() == "gal" && to_units == "L") {
        UValue result{val * 3.79, to_units};
        return result;
    }
    if (input.get_units() == "mi" && to_units == "km") {
        UValue result{val * 1.6, to_units};
        return result;
    }
    else {
        return input;
    }
}
