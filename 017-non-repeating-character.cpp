// 017-non-repeating-character.cpp
// Problem: Non Repeating Character (GeeksforGeeks 160 Days of Code)
// Difficulty: Easy
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(n)
// Space Complexity: O(1) — constant space for 26 lowercase letters

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        int freq[26] = {0};
        
        // count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // find the first character with frequency 1
        for (char c : s) {
            if (freq[c - 'a'] == 1)
                return c;
        }
        
        return '$';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    Solution sol;
    char ans = sol.nonRepeatingChar(s);
    cout << ans << '\n';

    return 0;
}
