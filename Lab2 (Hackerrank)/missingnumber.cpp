/*
An array contains distinct integers selected from the range 1 to N. Exactly one integer from this range is missing.
Find and print the missing integer.
Input Format
The first line contains an integer N.
The second line contains N − 1 distinct space-separated integers from the range 1 to N.
Constraints
2 <= N <= 100000
1 <= Ai <= N
Output Format
Print the missing number.
Sample Input 0
5
1 2 3 5
Sample Output 0
4
Explanation 0
The complete range of numbers is:
1 2 3 4 5
The number 4 does not appear in the array.
Hence the answer is 4.
Sample Input 1
10
1 2 3 4 5 6 7 9 10
Sample Output 1
8
Explanation 1
The complete range of numbers is:
1 2 3 4 5 6 7 8 9 10
The number 8 is missing from the array.
Hence the answer is 8.
*/


#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum = sum + x;
    }
    cout << total - sum;
    return 0;
}