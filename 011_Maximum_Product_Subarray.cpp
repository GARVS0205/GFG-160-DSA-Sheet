// 011_Maximum_Product_Subarray.cpp
// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// Difficulty: Medium
// Accuracy: 18.09%
// Points: 4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int curr_min = arr[0];
        int curr_max = arr[0];
        int max_prod = arr[0];

        for (int i = 1; i < n; i++) {
            int temp_max = max(arr[i], max(curr_min * arr[i], curr_max * arr[i]));
            curr_min = min(arr[i], min(curr_min * arr[i], curr_max * arr[i]));
            curr_max = temp_max;

            if (max_prod < curr_max) {
                max_prod = curr_max;
            }
        }
        return max_prod;
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
    cout << obj.maxProduct(arr) << endl;

    return 0;
}
