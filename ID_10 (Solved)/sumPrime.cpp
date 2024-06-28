#include <iostream>


int main(){

    int number;
    long long sum=2;
    for (number = 3; number < 2000000; number += 2)
    {
        bool isprime = true;
        for (int i = 3; i < number; i+= 2)
        {
            if (number % i == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime)
        {
            sum += number;
        }
        
    }
    std::cout << sum << std::endl;
    
}