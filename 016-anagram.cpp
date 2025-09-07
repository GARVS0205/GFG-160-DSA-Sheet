// 016-anagram.cpp
// Problem: Anagram (GeeksforGeeks 160 Days of Code)
// Difficulty: Easy
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(n + m)
// Space Complexity: O(1) — constant space for 26 letters

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // frequency arrays for 26 lowercase English letters
        int freq1[26] = {0};
        int freq2[26] = {0};

        for (char c : s1) {
            freq1[c - 'a']++;
        }
        for (char c : s2) {
            freq2[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    bool ans = sol.areAnagrams(s1, s2);
    cout << (ans ? "true" : "false") << '\n';

    return 0;
}
