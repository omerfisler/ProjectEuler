#include <iostream>

using namespace std;

int main() {
    
    long long num = 600851475143;
    int i = 2;
    int largestPrime = 0;
    while(largestPrime <= num){
        if (num % i == 0){
            num /= i;
            largestPrime = i;
        }
        else{
            i++;
        }
        
    }
    cout << largestPrime << endl;

}