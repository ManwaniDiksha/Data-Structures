/*
Explain the concepts of encapsulation and abstraction in C++ using a Bank Account example.
Implement functions deposit(), withdraw(), and get_balance() to demonstrate these concepts.
*/



#include <iostream>
using namespace std;

class BankAcc
{
private:
    int balance = 0;

public:

    void deposit(int amount)
    {
        balance = balance + amount;
    }

    void withdraw(int amount)
    {
        balance = balance - amount;
    }

    int get_balance()
    {
        return balance;
    }
};

int main()
{
    BankAcc account;

    account.deposit(1000);
    account.withdraw(300);

    cout << "Balance = " << account.get_balance() << endl;

    return 0;
}