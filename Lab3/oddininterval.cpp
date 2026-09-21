/*
Given two non-negative integers low and high, return the count of odd numbers between low and high (inclusive).

For example, if low = 3 and high = 7, the odd numbers in the range are:

3, 5, 7

Therefore, the answer is 3.

Input Format

The first line contains two space-separated non-negative integers low and high.

Constraints

0 <= low <= high <= 10^9

Output Format

Print a single integer representing the count of odd numbers between low and high, inclusive.

Sample Input 0

3 7
Sample Output 0

3
Explanation 0

The odd numbers between 3 and 7 are:

3 5 7

There are 3 odd numbers.

Hence, the answer is 3.

Sample Input 1

8 10
Sample Output 1

1
Explanation 1

The only odd number between 8 and 10 is:

9

Hence, the answer is 1.
*/

#include <iostream>
using namespace std;

int main()
{
    long long low, high;
    cin >> low >> high;

    long long firstodd, lastodd;

    if(low % 2 != 0)
    {
        firstodd = low;
    }
    else{
        firstodd = low + 1;
    }

    if(high % 2 != 0)
    {
        lastodd = high;
    }
    else{
        lastodd = high - 1;
    }


    long long count;
    if(firstodd > lastodd)
    {
        count = 0;
    }
    else
    {
        count = (lastodd - firstodd)/2 + 1;
    }

    cout << count << endl;
}