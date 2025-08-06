// 🔹 Problem: Move All Zeroes to End
// 🔗 Link: https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
// 🧠 Topic: Arrays
// 🧑‍💻 Solved on: 07-Aug-2025
// ✅ Difficulty: Easy | ⏱️ Expected Time Complexity: O(n), Space: O(1)

/*
Given an array arr[] of non-negative integers, move all zeros to the end
while maintaining the order of non-zero elements. Do it in-place.

Examples:
Input:  [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]

Input:  [10, 20, 30]
Output: [10, 20, 30]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }
        while(index < n) {
            arr[index++] = 0;
        }
    }
};
