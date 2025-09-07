// 🔹 Q013 - Smallest Positive Missing Number
// 📂 GFG Practice: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
//
// Problem Statement:
// You are given an integer array arr[]. Your task is to find the smallest positive number 
// missing from the array.
//
// Note: Positive numbers start from 1. The array can also have negative integers.
//
// -------------------------------------------------------------------
// Examples:
//
// Input: arr[] = [2, -3, 4, 1, 1, 7]
// Output: 3
// Explanation: Smallest positive missing number is 3.
//
// Input: arr[] = [5, 3, 2, 5, 1]
// Output: 4
// Explanation: Smallest positive missing number is 4.
//
// Input: arr[] = [-8, 0, -1, -4, -3]
// Output: 1
// Explanation: Smallest positive missing number is 1.
//
// -------------------------------------------------------------------
// Constraints:
// 1 ≤ arr.size() ≤ 10^5
// -10^6 ≤ arr[i] ≤ 10^6
//
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
//
// -------------------------------------------------------------------
// ✅ Solution: Sorting + Linear Scan
// (This approach uses sorting, so O(n log n), but still accepted. 
//  Optimized O(n) with constant space is possible via index placement technique.)
// -------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // sort the array
        int missing = 1; // start with 1 as smallest positive

        for(int i = 0; i < n; i++) {
            if(arr[i] == missing) {
                missing++; // move to next missing
            }
        }
        return missing;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << sol.missingNumber(arr) << endl; // Output: 3
    return 0;
}
