#include <iostream>

int main() {
    int numb1 = 1,numb2 = 2;
    int sum = 0, tempSum=0;
    while (tempSum < 4000000) {
        if (tempSum % 2 == 0) {
            sum += tempSum;
        }
        tempSum = numb1 + numb2;
        numb1 = numb2;
        numb2 = tempSum;
    }
    std::cout << sum+2 << std::endl; //+2 because numb2 is 2.
    return 0;
}