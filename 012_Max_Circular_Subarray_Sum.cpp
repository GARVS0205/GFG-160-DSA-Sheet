/*
Problem: Maximum Circular Subarray Sum
Difficulty: Hard
GFG Link: https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. 
In a circular array, the subarray can start at the end and wrap around to the beginning. 
Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

----------------------------------------------------
Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array (12), 
and moving circularly: [12, 8, -8, 9, -9, 10] → sum = 22

Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Max circular subarray = [7, 6, 5, -4, -1, 10] → sum = 23

Input: arr[] = [5, -2, 3, 4]
Output: 12
Explanation: Max circular subarray = [3, 4, 5] → sum = 12

----------------------------------------------------
Constraints:
1 ≤ arr.size() ≤ 1e5
-1e4 ≤ arr[i] ≤ 1e4

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
----------------------------------------------------
Approach:
1. Use Kadane’s Algorithm to find:
   - max subarray sum (non-circular case)
   - min subarray sum (to handle circular case)
   - total array sum
2. If all elements are negative → return maxKadane
3. Else return max(maxKadane, totalSum - minKadane)
----------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = arr[0];
        int maxKadane = arr[0], minKadane = arr[0];
        int currentMax = arr[0], currentMin = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            // Standard Kadane for max subarray
            currentMax = max(arr[i], currentMax + arr[i]);
            maxKadane = max(maxKadane, currentMax);

            // Modified Kadane for min subarray
            currentMin = min(arr[i], currentMin + arr[i]);
            minKadane = min(minKadane, currentMin);

            totalSum += arr[i];
        }

        // If all elements are negative → totalSum == minKadane
        if (totalSum == minKadane) return maxKadane;

        // Otherwise, max of (normal max subarray) and (circular subarray)
        return max(maxKadane, totalSum - minKadane);
    }
};

// Example usage
int main() {
    Solution s;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << s.maxCircularSum(arr) << endl;  // Output: 22
    return 0;
}
