#include <iostream>

using namespace std;

int main(){
    int largestPalindrome = 0;
    int product = 0,temp = 0,reverse = 0;
    for (int i = 999; i > 100; i--)
    {
        for (int j = 999; j > 100; j--)
        {
            product = i*j;
            temp = product;
            reverse = 0;
            while (temp != 0)
            {
                reverse = reverse*10 + temp%10;
                temp /= 10;
            }
            if (product == reverse && product > largestPalindrome)
            {
                largestPalindrome = product;
            }
        }
            
        /* code */
    }
    
    cout<<largestPalindrome<<endl;
    return 0;
}