#include<iostream>
#include <limits> // Add this line

using namespace std;

int main() {
    int n = 1;
    long long triangular = 0;
    while (n < 500)
    {
        triangular += n;
        n++;
    }
    
    while (true) {
        triangular += n; 
        n++;
        int count = 1; // except for number 1 itself
        for (int i = 1; i <= triangular/2; i++) {
            if (triangular % i == 0) {
                count++;
            }
        }
        if (count > 500) {
            cout << triangular << endl;
            break;
        }
    }
    cout << "Press enter to continue . . .";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
}