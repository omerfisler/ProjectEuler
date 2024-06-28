#include <stdio.h>

int main(){
    int squareNaturalNumbers = 0;
    int sumNaturalNumbers = 0;
    int squareSumOfNaturalNumbers = 0;
    for (int i = 1; i <= 100; i++)
    {
        squareNaturalNumbers += (i*i);
        sumNaturalNumbers += i;
    }
    squareSumOfNaturalNumbers = sumNaturalNumbers*sumNaturalNumbers;
    printf("The difference between squareSumOfNaturalNumbers and squareNaturalNumbers : %d",squareSumOfNaturalNumbers-squareNaturalNumbers );
    return 0;
}