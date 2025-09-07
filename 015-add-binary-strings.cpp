// 015-add-binary-strings.cpp
// Problem: Add Binary Strings (GeeksforGeeks 160 Days of Code)
// Difficulty: Medium
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = (int)s1.size() - 1;
        int j = (int)s2.size() - 1;
        int carry = 0;
        string res;
        res.reserve(max(s1.size(), s2.size()) + 1);

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            res.push_back(char((sum % 2) + '0'));
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());

        // remove leading zeros (but keep single "0" if result is all zeros)
        size_t k = res.find_first_not_of('0');
        return (k == string::npos) ? string("0") : res.substr(k);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    // Read two binary strings (space/newline separated)
    if (!(cin >> s1 >> s2)) return 0;

    Solution sol;
    string ans = sol.addBinary(s1, s2);
    cout << ans << '\n';
    return 0;
}
