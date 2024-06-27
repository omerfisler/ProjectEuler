#include <iostream>
#include <stdio.h>

using namespace std;
int* findNstPrimeNumbers(int n){ 
    int* primeNumbers = new int[n];
    primeNumbers[0] = 2;
    int count = 1;
    int number = 3;
    bool isprime;
    while (count < n)
    {
        isprime = true;
        for (int i = 0; i < count; i++)
        {
            if (number % primeNumbers[i] == 0)
            {
                isprime = false;
                break;
            }

        }
        if (isprime)
        {
            primeNumbers[count] = number;
            count++;
        }
        number += 2;
    }
    
    return primeNumbers;
}

int main(){
    int result;
    cin >> result;
    int* primeNumbers = findNstPrimeNumbers(result);
    for (int i = 0; i < result; i++) {
        cout<<"\t" << primeNumbers[i] << " ";
    }
    cout << endl;
    delete[] primeNumbers;
    return 0;
}