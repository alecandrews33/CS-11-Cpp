#include "units.h"

// This function prompts the user for a value and unit, and a unit to convert
// to. It uses stdio.
int main() {
    double value;
    string units;
    string to_units;

    cout << "Enter value with units: ";
    cin >> value >> units;
    UValue input = {value, units};

    cout << "Convert to units: ";
    cin >> to_units;
    UValue output = convert_to(input, to_units);

    // Print to console the result of conversion
    if (output.get_units() == to_units) {
        cout << "Converted to: " << output.get_value() <<
          " " << output.get_units() << endl;
    }
    else {
        cout << "Couldn't convert to " << to_units << "!" << endl;
    }
    return 0;
}
