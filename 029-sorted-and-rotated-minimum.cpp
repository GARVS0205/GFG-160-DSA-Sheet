// 029-sorted-and-rotated-minimum.cpp
// Problem: Sorted and Rotated Minimum (GeeksforGeeks 160 Days of Code)
// Difficulty: Easy
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(const vector<int>& arr) {
        int n = (int)arr.size();
        if (n == 0) return -1;
        if (n == 1) return arr[0];

        int low = 0, high = n - 1;
        while (low <= high) {
            // if subarray is already sorted, the leftmost is minimum
            if (arr[low] <= arr[high]) return arr[low];

            int mid = low + (high - low) / 2;

            // check if mid is the minimum (pivot)
            if (mid > 0 && arr[mid] < arr[mid - 1]) return arr[mid];

            // decide which half to choose
            if (arr[mid] >= arr[low]) {
                // left part is sorted, pivot must be in right part
                low = mid + 1;
            } else {
                // right part is sorted, pivot in left part
                high = mid - 1;
            }
        }
        return -1; // should not reach for valid rotated sorted array
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // n
    // arr[0] arr[1] ... arr[n-1]
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Solution sol;
    int ans = sol.findMin(arr);
    cout << ans << '\n';
    return 0;
}
