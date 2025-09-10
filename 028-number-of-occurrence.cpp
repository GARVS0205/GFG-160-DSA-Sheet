// 028-number-of-occurrence.cpp
// Problem: Number of occurrence (GeeksforGeeks 160 Days of Code)
// Difficulty: Easy
// Solved by: Garv Sachdeva
// Date: 2025-09-07
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int firstOccurence(const vector<int>& arr, int target) {
        int low = 0, high = (int)arr.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurence(const vector<int>& arr, int target) {
        int low = 0, high = (int)arr.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int countFreq(const vector<int>& arr, int target) {
        int first = firstOccurence(arr, target);
        if (first == -1) return 0;
        int last = lastOccurence(arr, target);
        return last - first + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // n
    // arr[0] arr[1] ... arr[n-1]
    // target
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int target;
    cin >> target;

    Solution sol;
    int ans = sol.countFreq(arr, target);
    cout << ans << '\n';
    return 0;
}
