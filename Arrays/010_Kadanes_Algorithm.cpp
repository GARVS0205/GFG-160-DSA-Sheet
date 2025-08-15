// 010_Kadanes_Algorithm.cpp
// Problem Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Difficulty: Medium
// Accuracy: 36.28%
// Points: 4
// Average Time: 20m

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int result = arr[0];
        int max_ending = arr[0];

        for (int i = 1; i < n; i++) {
            max_ending = max(arr[i], max_ending + arr[i]);
            result = max(result, max_ending);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxSubarraySum(arr) << endl;

    return 0;
}
