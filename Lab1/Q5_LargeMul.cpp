/*
Write a C++ program to perform multiplication of two large integers (numbers too large to fit
into built-in integer types). You are required to implement two different methods:
1. Primary School Method
- Implement the digit-by-digit multiplication algorithm, similar to the way multiplication is
taught in school.
- Operate directly on string or vector representations of the numbers.
2. Karatsuba Multiplication Method
- Implement the recursive Karatsuba algorithm for large number multiplication.
- Compare its performance with the primary school method for various input sizes.
Input:
- Two non-negative integers (each can have up to 10,000 digits).
- The numbers will be provided as strings.

Output:
- Display the product of the two numbers using the primary school method.
- Display the product using the Karatsuba method.
- Optionally, measure and display the execution time for each method.
Example:
• Input:
123456789
987654321
• Output (Primary School Method):
121932631112635269
• Output (Karatsuba Method):
121932631112635269
Tasks:
1. Implement string multiplyPrimarySchool(string a, string b) for the primary school method.
2. Implement string multiplyKaratsuba(string a, string b) for the Karatsuba method.
3. Ensure both methods handle leading zeros correctly and work for very large inputs.
4. Compare execution time for inputs of different sizes.
*/



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