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