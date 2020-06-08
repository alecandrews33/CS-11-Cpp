#include "units.h"

UnitConverter init_converter() {
    UnitConverter converter;
    converter.add_conversion("mi", 5280, "ft");
    converter.add_conversion("mi", 1.6, "km");
    converter.add_conversion("ft", 12, "in");
    converter.add_conversion("in", 2.54, "cm");
    converter.add_conversion("lb", 0.45, "kg");
    converter.add_conversion("stone", 14, "lb");
    converter.add_conversion("lb", 16, "oz");
    converter.add_conversion("kg", 1000, "g");
    converter.add_conversion("gal", 3.79, "L");
    converter.add_conversion("bushel", 9.3, "gal");
    converter.add_conversion("ft^3", 7.5, "gal");
    converter.add_conversion("L", 1000, "ml");
    return converter;
}

int main() {
    UnitConverter u = init_converter();

    // Get the input value-with-units
    double value;
    string units;
    string to_units;

    cout << "Enter value with units: ";
    cin >> value >> units;
    UValue input = UValue(value, units);

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
    }
    return 0;
}
