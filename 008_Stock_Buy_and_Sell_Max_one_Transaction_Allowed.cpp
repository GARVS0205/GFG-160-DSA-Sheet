// 🔹 Problem: Stock Buy and Sell – Max one Transaction Allowed
// 🔗 Link: https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
// 🧠 Topic: Arrays
// 🧑‍💻 Solved on: 11-Aug-2025
// ✅ Difficulty: Easy | ⏱️ Avg. Time: 10 mins | 💡 Expected TC: O(n), SC: O(1)

/*
Given an array prices[] representing stock prices on different days, find the 
maximum profit possible when at most one transaction is allowed.

One transaction = 1 buy + 1 sell.
If no profit is possible, return 0.
Note: You must buy before selling.

Examples:
Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: Buy on day 2 at price = 1, sell on day 5 at price = 9 => profit = 8

Input: prices[] = [7, 6, 4, 3, 1]
Output: 0
Explanation: Prices are decreasing, no profitable transaction.

Input: prices[] = [1, 3, 6, 9, 11]
Output: 10
Explanation: Buy at price 1, sell at price 11 => profit = 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (int price : prices) {
            if (price < min_price) {
                min_price = price;
            }
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        
        return max_profit;
    }
};

// Example usage:
// int main() {
//     vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
//     Solution obj;
//     cout << obj.maximumProfit(prices) << endl; // Output: 8
// }
