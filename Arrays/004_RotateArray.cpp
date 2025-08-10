// Problem: Rotate Array
// Difficulty: Medium
// Link: https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (d == 0 || d == n) return;
        d = d % n; // Handle if d > n
        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);
    }
};
