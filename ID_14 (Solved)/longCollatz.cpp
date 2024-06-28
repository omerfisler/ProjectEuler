#include <iostream>

using namespace std;

int main()
{
    int maxCount = 0;
    long long maxNum = 0;
    for (int i = 1; i < 1000000; i++)
    {
        long long num = i;
        int count = 1;
        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num = 3 * num + 1;
            }
            count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            maxNum = i;
        }
    }

    cout << maxNum << endl;
    cout << "and the chain such like that:"<< endl;
    while (maxNum > 1)
    {
        if (maxNum % 2 == 0)
        {
            maxNum /= 2;
            cout << "Even:\tDivided by 2\t               \t\t==> " << maxNum << endl;
        }
        else
        {
            maxNum = 3 * maxNum + 1;
            cout << "Odd:\tMultiplied by 3 and added 1\t\t==> " << maxNum << endl;
        }
        
    }

    return 0;
}