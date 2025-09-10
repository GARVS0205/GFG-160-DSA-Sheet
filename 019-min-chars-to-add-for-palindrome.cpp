// 019-min-chars-to-add-for-palindrome.cpp
// Problem: Minimum Characters to Add for Palindrome (GeeksforGeeks 160 Days of Code)
// Difficulty: Hard
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minChar(string &s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Concatenate original + '#' + reversed
        string temp = s + '#' + rev;
        int n = temp.size();
        
        // Build LPS array (like KMP)
        vector<int> lps(n, 0);
        int len = 0;
        
        for (int i = 1; i < n;) {
            if (temp[i] == temp[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
        
        return (int)(s.size() - lps[n - 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    Solution sol;
    int ans = sol.minChar(s);
    cout << ans << '\n';

    return 0;
}
