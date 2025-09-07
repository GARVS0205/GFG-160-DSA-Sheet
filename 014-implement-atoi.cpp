// 014-implement-atoi.cpp
// Problem: Implement Atoi (GeeksforGeeks 160 Days of Code)
// Difficulty: Medium
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
#include <climits>

class Solution {
  public:
    int myAtoi(string& s) {
        // original logic preserved
        int i = 0, n = s.length();
        int sign = 1;
        long long result = 0;

        // skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // convert characters to integer
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // handle overflow
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);  // read full line (including leading spaces)

    Solution sol;
    int ans = sol.myAtoi(s);
    cout << ans << '\n';

    return 0;
}
