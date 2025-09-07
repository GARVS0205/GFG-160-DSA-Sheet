// 🔹 Problem: Next Permutation
// 🔗 Link: https://www.geeksforgeeks.org/problems/next-permutation5226/1
// 🧠 Topic: Arrays
// 🧑‍💻 Solved on: 10-Aug-2025
// ✅ Difficulty: Medium | ⏱️ Avg. Time: 20 mins | 💡 Expected TC: O(n), SC: O(1)

/*
Given an array of integers arr[] representing a permutation, 
implement the next permutation that rearranges the numbers into 
the lexicographically next greater permutation. 

If no such permutation exists, rearrange the numbers into the 
lowest possible order (i.e., sorted in ascending order).

Examples:
Input:  arr[] = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]

Input:  arr[] = [3, 2, 1]
Output: [1, 2, 3]

Input:  arr[] = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        // Step 2: If such element found, find the next larger element and swap
        if (i >= 0) {
            int j = n - 1;
            while (arr[j] <= arr[i]) {
                j--;
            }
            swap(arr[i], arr[j]);
        }

        // Step 3: Reverse the suffix
        reverse(arr.begin() + i + 1, arr.end());
    }
};
