/*
Given an array of integers, find the second largest distinct element in the array.
The second largest distinct element is the largest value that is strictly smaller than the maximum element.
Duplicate values should be considered only once.
If the array contains fewer than two distinct elements, print -1.
Hints
Hint 1: You do not need to sort the array.
Hint 2: Traverse the array once while maintaining the largest and second largest distinct values.
Hint 3: Ignore duplicate values when updating the answer.
Expected Time Complexity: O(N) Expected Auxiliary Space: O(1)
Input Format
The first line contains an integer N, the number of elements.
The second line contains N space-separated integers.
Constraints
2 <= N <= 100000
-10^9 <= Ai <= 10^9
Output Format
Print the second largest distinct element.
If there are fewer than two distinct values, print -1.
Sample Input 0
6
12 35 1 10 34 1
Sample Output 0
34
Explanation 0
The distinct elements are:
1 10 12 34 35
The largest distinct element is 35.
The second largest distinct element is 34.
Hence the answer is 34.
Sample Input 1
4
7 7 7 7
Sample Output 1
-1
Explanation 1
The distinct elements are:
7
The largest distinct element is 7.
There is no second largest distinct element because the array contains only one distinct value.
Hence the answer is -1.
*/



#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    long long largest, second;
    cin >> largest;
    bool foundSecond = false;

    for (int i = 1; i < n; i++) {
        long long x;
        cin >> x;
        if (x > largest) {
            second = largest;
            largest = x;
            foundSecond = true;
        }
        else if (x < largest) {
            if (!foundSecond || x > second) {
                second = x;
                foundSecond = true;
            }
        }
    }

    if (foundSecond)
        cout << second << endl;
    else
        cout << -1 << endl;

    return 0;
}