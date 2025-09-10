// 018-search-pattern.cpp
// Problem: Search Pattern (KMP) (GeeksforGeeks 160 Days of Code)
// Difficulty: Hard
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(n + m)
// Space Complexity: O(m)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
       vector<int> lps(pat.size(), 0);
       vector<int> result;
       int len = 0;
       // build LPS array
       for (int i = 1; i < (int)pat.size();) {
           if (pat[i] == pat[len]) {
               lps[i++] = ++len;
           } else {
               if (len != 0) len = lps[len - 1];
               else lps[i++] = 0;
           }
       }

       int i = 0, j = 0; // i -> index for txt, j -> index for pat
       while (i < (int)txt.size()) {
           if (txt[i] == pat[j]) {
               i++;
               j++;
               if (j == (int)pat.size()) {
                   result.push_back(i - j); // match found at i-j (0-based)
                   j = lps[j - 1];
               }
           } else {
               if (j != 0) j = lps[j - 1];
               else i++;
           }
       }
       return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string txt, pat;
    // Read two space/newline separated strings (txt then pat)
    if (!(cin >> txt >> pat)) return 0;

    Solution sol;
    vector<int> ans = sol.search(pat, txt);

    // Print indices space-separated on one line.
    // If no occurrences, print nothing (just a newline).
    for (size_t k = 0; k < ans.size(); ++k) {
        if (k) cout << ' ';
        cout << ans[k];
    }
    cout << '\n';
    return 0;
}
