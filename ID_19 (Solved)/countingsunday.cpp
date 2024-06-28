#include <iostream>

using namespace std;

int main()
{
    int year{1900}, month{1}, day{1}, weekday{0}, sundays{0};
    while (year < 2001)
    {
        if (weekday == 6 && day == 1)
        {
            if (year > 1900)
            {
                sundays++;
            }
        }

        if (month == 2)
        {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                if (day == 29)
                {
                    day = 0;
                    month++;
                }
            }
            else
            {
                if (day == 28)
                {
                    day = 0;
                    month++;
                }
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day == 30)
            {
                day = 0;
                month++;
            }
        }
        else
        {
            if (day == 31)
            {
                day = 0;
                month++;
            }
        }
        if (month == 13)
        {
            month = 1;
            year++;
        }
        weekday = (weekday + 1) % 7;
        day++;
    }
    cout << sundays << endl;
    return 0;
}