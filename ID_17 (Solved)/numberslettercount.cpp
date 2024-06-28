#include <iostream>
#include <string>

using namespace std;

// Enum for letters in number words
enum digitsletters {
    one = 3, two = 3, three = 5, four = 4, five = 4, six = 3, seven = 5, eight = 5, nine = 4, ten = 3,
    eleven = 6, twelve = 6, thirteen = 8, fourteen = 8, fifteen = 7, sixteen = 7, seventeen = 9, eighteen = 8, nineteen = 8,
    twenty = 6, thirty = 6, forty = 5, fifty = 5, sixty = 5, seventy = 7, eighty = 6, ninety = 6, hundred = 7,
    aand = 3, thousand = 8, onethousand = 11
};

// Arrays to map numbers to their corresponding enum values
const int belowTwenty[] = {0, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen};
const int tens[] = {0, 0, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety};

int main() {
    int sum = 0;

    for (int i = 1; i <= 1000; ++i) {
        if (i == 1000) {
            sum += onethousand;
        } else if (i >= 100) {
            if (i % 100 == 0) {
                sum += belowTwenty[i / 100] + hundred;
            } else {
                sum += belowTwenty[i / 100] + hundred + aand;
                if (i % 100 <= 19) {
                    sum += belowTwenty[i % 100];
                } else {
                    sum += tens[(i % 100) / 10] + belowTwenty[i % 10];
                }
            }
        } else if (i <= 19) {
            sum += belowTwenty[i];
        } else {
            sum += tens[i / 10] + belowTwenty[i % 10];
        }
    }

    cout << "The sum of the letters of the numbers from 1 to 1000 is: " << sum << endl;

    return 0;
}
