// 🔹 Problem: Majority Element - More Than n/3
// 🔗 Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
// 🧠 Topic: Arrays / Boyer–Moore Majority Vote
// 🧑‍💻 Solved on: 10-Aug-2025
// ✅ Difficulty: Medium | ⏱️ Avg. Time: 15 mins | 💡 Expected TC: O(n), SC: O(1)

/*
Given an array arr[] consisting of n integers, the task is to find all the array 
elements which occur more than floor(n/3) times.

Note: The returned array of majority elements should be sorted.

Examples:
Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor(8/3) = 2.

Input: arr[] = [-5, 3, -5]
Output: [-5]
Explanation: The frequency of -5 is 2, which is more than floor(3/3) = 1.

Input: arr[] = [3, 2, 2, 4, 1, 4]
Output: []
Explanation: There is no majority element.

Constraints:
1 ≤ arr.size() ≤ 10^6
-10^5 ≤ arr[i] ≤ 10^5
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        // First pass: Find potential candidates
        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: Count actual occurrences
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        // Collect results
        vector<int> res;
        if (count1 > n / 3) res.push_back(candidate1);
        if (count2 > n / 3) res.push_back(candidate2);
        sort(res.begin(), res.end());
        return res;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> result = sol.findMajority(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
