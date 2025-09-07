// Problem: Reverse an Array
// Difficulty: Easy
// Link: https://practice.geeksforgeeks.org/problems/reverse-an-array/0

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int m = n - 1;
        int i = 0;
        while (i < n / 2) {
            swap(arr[i], arr[m]);
            i++;
            m--;
        }
    }
};
