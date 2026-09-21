#include <iostream>
#include <string>
using namespace std;

string removeZeros(string s){
    int i = 0;
    while (i < s.length() - 1 && s[i] == '0')
        i++;
    return s.substr(i);
}

string add(string a, string b){
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry){
        int x = (i >= 0) ? a[i] - '0' : 0;
        int y = (j >= 0) ? b[j] - '0' : 0;
        int sum = x + y + carry;
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
        i--;
        j--;
    }

    return removeZeros(result);
}

string subtract(string a, string b){
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int borrow = 0;
    while (i >= 0){
        int x = (a[i] - '0') - borrow;
        int y = (j >= 0) ? b[j] - '0' : 0;
        if (x < y){
            x += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        result = char(x - y + '0') + result;
        i--;
        j--;
    }
    return removeZeros(result);
}

string multiplyPrimarySchool(string a, string b){
    a = removeZeros(a);
    b = removeZeros(b);
    if (a == "0" || b == "0")
        return "0";

    string result = "0";

    for (int i = b.length() - 1, zeros = 0; i >= 0; i--, zeros++){
        int digit = b[i] - '0';
        int carry = 0;
        string temp = "";
        for (int j = a.length() - 1; j >= 0; j--){
            int product = (a[j] - '0') * digit + carry;

            temp = char(product % 10 + '0') + temp;
            carry = product / 10;
        }

        if (carry)
            temp = char(carry + '0') + temp;

        temp += string(zeros, '0');

        result = add(result, temp);
    }
    return result;
}

string multiplyKaratsuba(string a, string b){
    a = removeZeros(a);
    b = removeZeros(b);
    if (a == "0" || b == "0")
        return "0";

    if (a.length() <= 2 || b.length() <= 2)
        return multiplyPrimarySchool(a, b);

    int n = max(a.length(), b.length());

    if (n % 2 != 0)
        n++;

    while (a.length() < n)
        a = "0" + a;

    while (b.length() < n)
        b = "0" + b;

    int half = n / 2;

    string a1 = a.substr(0, half);
    string a0 = a.substr(half);

    string b1 = b.substr(0, half);
    string b0 = b.substr(half);

    string z2 = multiplyKaratsuba(a1, b1);
    string z0 = multiplyKaratsuba(a0, b0);

    string z1 = multiplyKaratsuba(add(a1, a0), add(b1, b0));

    z1 = subtract(z1, z2);
    z1 = subtract(z1, z0);

    z2 += string(2 * half, '0');
    z1 += string(half, '0');

    return add(add(z2, z1), z0);
}

int main(){
    string a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    a = removeZeros(a);
    b = removeZeros(b);
    cout << endl;
    cout << "Primary School Result: "
         << multiplyPrimarySchool(a, b) << endl;
    cout << "Karatsuba Result: "
         << multiplyKaratsuba(a, b) << endl;
    return 0;
}