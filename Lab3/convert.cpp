#include "units.h"


UnitConverter init_converter(const string &filename) {
    UnitConverter converter;
    ifstream ifs{filename};

    // Make sure the file was opened successfully
    if (!ifs)
        throw invalid_argument("Couldn't open file");

    while (ifs) {
        string from_units;
        float multiplier;
        string to_units;
        ifs >> from_units;
        ifs >> multiplier;
        ifs >> to_units;
        converter.add_conversion(from_units, multiplier, to_units);
    }

    return converter;
}

int main() {
    try {
        UnitConverter u = init_converter("rules.txt");

        // Get the input value-with-units
        double value;
        string units;
        string to_units;

        cout << "Enter value with units: ";
        cin >> value >> units;
        UValue input = {value, units};

        cout << "Convert to units: ";
        cin >> to_units;

        // Output the results, or report an error in conversion
        try {
            UValue output = u.convert_to(input, to_units);
            cout << "Converted to: " << output.get_value() <<
                " " << output.get_units() << endl;
        }
        catch (invalid_argument e) {
            cout << e.what() << endl;
            return 1;
        }
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
