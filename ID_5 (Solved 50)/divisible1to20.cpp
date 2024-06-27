#include <iostream>

int main(){
    //For 1 to 10 (1,2,3,4,5,6,7,8,9,10)
    int divisible = 2520;
    for (int i = 10; i < 20; i++)
    {
        if (2520 % i == 0)
        {
            //DO Nothing
        }
        else
        {

            divisible *= i;
        }
    }
    printf("Smallest multiple: %d",divisible/8); // divided to 8 because I used 16 as a prime number and multiplied it completely.

    return 0;
}