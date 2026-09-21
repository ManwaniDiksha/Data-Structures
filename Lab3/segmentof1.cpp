/*
You are given a binary string S consisting only of '0' and '1'.

A segment of 1s is a contiguous group of one or more '1' characters.

The string is considered valid if it contains at most one contiguous segment of 1s.

In other words, after a group of 1s ends, no more 1s should appear later in the string.

Your task is to determine whether the given binary string has at most one segment of 1s.

Print "true" if the condition is satisfied.

Print "false" otherwise.

Input Format

The first line contains an integer N, representing the length of the binary string.

The second line contains a binary string S of length N.

Constraints

1 ≤ N ≤ 100 S contains only '0' and '1'.

Output Format

Print "true" if the string has at most one contiguous segment of 1s.

Print "false" if the string has two or more separate segments of 1s.

Sample Input 0

4
1001
Sample Output 0

false
Explanation 0

The string "1001" contains two separate segments of 1s: - The first segment is "1" at the beginning. - The second segment is "1" at the end.

Therefore, the answer is false.

Sample Input 1

7
1111000
Sample Output 1

true
Explanation 1

The string "1111000" contains only one contiguous segment of 1s.

Therefore, the answer is true.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int segments = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='1' && (i==0 || s[i-1]=='0'))
        {
            segments++;
        }
    }

    if(segments > 1)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}