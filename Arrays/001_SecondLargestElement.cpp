// 🔹 Problem: Second Largest Element
// 🔗 Link: https://www.geeksforgeeks.org/problems/second-largest3735/1
// 🧠 Topic: Arrays
// 🧑‍💻 Solved on: 06-Aug-2025
// ✅ Difficulty: Easy | ⏱️ Avg. Time: 15 mins | 💡 Expected TC: O(n), SC: O(1)

/*
Given an array of positive integers arr[], return the second largest element
from the array. If the second largest element doesn't exist then return -1.

Examples:
Input:  arr[] = [12, 35, 1, 10, 34, 1]
Output: 34

Input:  arr[] = [10, 5, 10]
Output: 5

Input:  arr[] = [10, 10, 10]
Output: -1
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = INT_MIN;
        int secondlargest = INT_MIN;

        for (int num : arr) {
            if (num > largest) {
                secondlargest = largest;
                largest = num;
            } else if (num > secondlargest && num != largest) {
                secondlargest = num;
            }
        }

        return (secondlargest == INT_MIN) ? -1 : secondlargest;
    }
};

