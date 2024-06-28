#include <iostream>
#include <vector>
#include <chrono> // To calculate the execution time.

using namespace std;
using namespace std::chrono;

int main(){
    int n;
    cout << "Enter a factorial to calculate sum of digits: ";
    do
    {
        cin >> n;
        if (n <= 0)
            cout << "Invalid input. Try to type a number greater than 0: ";
    } while (n <= 0);

    auto start = high_resolution_clock::now(); // Start timing

    vector<int> factorial{1};
    int carry{0}, product{0};
    while (n) // Calculating factorial by using vector and carry method for large numbers
    {
        for (int i = 0; i < factorial.size(); i++)
        {
            product = factorial[i] * n + carry;
            factorial[i] = product % 10;
            carry = product / 10;
        }
        while (carry)
        {
            factorial.push_back(carry % 10);
            carry /= 10;
        }
        n--;
    }
    // Sum of digits:
    int sum{0};
    for (int i = factorial.size() - 1; i >= 0; i--)
    {
        sum += factorial[i];
        // cout << factorial[i]<< " ";      // Uncomment this line to see the factorial number
    }

    auto stop = high_resolution_clock::now();                 // End timing
    auto duration = duration_cast<nanoseconds>(stop - start); // Calculate duration in nanoseconds
    cout << "Execution time: " << duration.count() << " nanoseconds (which equals to " << duration.count() / 1e6 << " milliseconds)" << endl;

    cout << "Sum of digits: " << sum << endl;
}