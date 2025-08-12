// Problem: Minimize the Heights II
// Link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Difficulty: Medium
// Expected Time Complexity: O(n log n)
// Expected Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int min_height = min(smallest, arr[i + 1] - k);
            int max_height = max(largest, arr[i] + k);
            if (min_height < 0) continue;
            ans = min(ans, max_height - min_height);
        }
        return ans;
    }
};

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.getMinDiff(arr, k) << "\n";
    return 0;
}
