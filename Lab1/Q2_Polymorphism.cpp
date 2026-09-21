/*
Demonstrate the concept of polymorphism in C++ using an example of different payment
methods. Implement functions UPI(), CreditCard(), and NetBanking() to represent different
payment modes.
*/


#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay()
    {
        cout << "Payment" << endl;
    }
};

class UPI : public Payment
{
public:
    void pay()
    {
        cout << "UPI Payment" << endl;
    }
};

class CreditCard : public Payment
{
public:
    void pay()
    {
        cout << "Credit Card Payment" << endl;
    }
};

class NetBanking : public Payment
{
public:
    void pay()
    {
        cout << "Net Banking Payment" << endl;
    }
};

int main()
{
    Payment *payment;

    UPI upi;
    payment = &upi;
    payment->pay();

    CreditCard card;
    payment = &card;
    payment->pay();

    NetBanking netBanking;
    payment = &netBanking;
    payment->pay();

    return 0;
}