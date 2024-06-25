#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    for (a = 1; a < 500; a++)
    {
        for (b = a + 1; b < 500; b++)
        {
            c = 1000 - a - b;
            if (a * a + b * b == c * c)
            {
                cout << a << " " << b << " " << c << endl;
                cout << a * b * c << endl;
            }
        }
    }
    return 0;
    
}