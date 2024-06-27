#include <iostream>
#include <vector>
#include <chrono> // Include the chrono library

using namespace std;
using namespace chrono; // Use the namespace of chrono

int main()
{
    auto start = high_resolution_clock::now(); // Start timing

    vector<int> digits;
    digits.push_back(1);

    for (int i = 0; i < 1000; i++)
    {
        int carry = 0;
        for (int j = 0; j < digits.size(); j++)
        {
            int product = digits[j] * 2 + carry;
            digits[j] = product % 10;
            carry = product / 10;
        }
        if (carry > 0)
        {
            digits.push_back(carry);
        }
    }
    long long sum = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        sum += digits[i];
    }
    cout << sum << endl;
    

    auto stop = high_resolution_clock::now();                          // End timing
    auto duration = duration_cast<nanoseconds>(stop - start); // Calculate duration in nanoseconds

    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
    
