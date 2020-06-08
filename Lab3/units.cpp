#include "units.h"

// Two argument constructor for UValue class. Takes in a value and units.
UValue::UValue(double value, const string &units) {
    this->value = value;
    this->units = units;
}

// Returns the value (double) of the object. No inputs.
double UValue::get_value() const {
    return this->value;
}

// Returns the units (string) of the object. No inputs.
string UValue::get_units() const {
    return this->units;
}

/* Tries to convert from one UValue to the units specified
 * by the to_units string. Returns input UValue if unable to
 * convert. Input is a UValue and a string for destination units.
 * Output is a UValue.
 */
UValue convert_to(const UValue &input, const string &to_units) {
    double val = input.get_value();
    if (input.get_units() == "lb" && to_units == "kg") {
        return UValue{val * 0.45, to_units};
    }
    if (input.get_units() == "gal" && to_units == "L") {
        return UValue{val * 3.79, to_units};
    }
    if (input.get_units() == "mi" && to_units == "km") {
        return UValue{val * 1.6, to_units};
    }
    else {
        return input;
    }
}

void UnitConverter::add_conversion(const string &from_units,
    const double &multiplier, const string &to_units) {
    for (size_t i = 0; i < conVec.size(); i++) {
        if (conVec[i].from_units == from_units &&
            conVec[i].to_units == to_units) {
            string err = "Already have a conversion from " + from_units + \
                " to " + to_units;
            throw invalid_argument(err);
        }
    }

    // If we reach this point, we know the conversion is new
    Conversion c1 = {from_units, multiplier, to_units};
    Conversion c2 = {to_units, 1/multiplier, from_units};
    conVec.push_back(c1);
    conVec.push_back(c2);
}
UValue UnitConverter::convert_to(const UValue &input,
    const string &to_units) const {
        return this->convert_to(input, to_units, set<string>());
    }

UValue UnitConverter::convert_to(const UValue &input,
    const string &to_units, set<string> seen) const {

    seen.insert(input.get_units());

    // Search through all conversions to find this conversion.
    for (size_t i = 0; i < conVec.size(); i++) {
        if (conVec[i].from_units == input.get_units()) {
            if (conVec[i].to_units == to_units) {
                // Return new UValue if found.
                return UValue(input.get_value() * conVec[i].multiplier,
                    to_units);
            }
            else if (seen.count(conVec[i].to_units) == 0) {
                UValue change = UValue(input.get_value() * conVec[i].multiplier,
                    conVec[i].to_units);
                try {
                    return this->convert_to(change, to_units, seen);
                }
                catch (invalid_argument e){};
            }
        }
    }

    // If we reach this point, then this conversion failed!
    string err = "Don't know how to convert from " + input.get_units() + \
        " to " + to_units;
    throw invalid_argument(err);
}
