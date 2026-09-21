#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int number = 100; number <= 2000; number++)
    {
        int originalNumber = number;
        int digits = 0;
        int temp = number;
        while (temp > 0)
        {
            digits++;
            temp = temp / 10;
        }

        int sum = 0;
        temp = number;

        while (temp > 0)
        {
            int digit = temp % 10;
            sum = sum + pow(digit, digits);
            temp = temp / 10;
        }

        if (sum == originalNumber)
        {
            cout << number << " is an Armstrong number." << endl;
        }
    }
    return 0;
}