// 🔹 Problem: Stock Buy and Sell – Multiple Transaction Allowed
// 🔗 Link: https://www.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
// 🧠 Topic: Arrays
// 🧑‍💻 Solved on: 11-Aug-2025
// ✅ Difficulty: Medium | ⏱️ Avg. Time: 15 mins | 💡 Expected TC: O(n), SC: O(1)

/*
The cost of stock on each day is given in an array price[]. Each day you may decide to either 
buy or sell the stock at price[i]. You can even buy and sell the stock on the same day.

Find the maximum profit you can get.

Note: 
- You can only sell stock if it has been bought previously.
- Multiple stocks cannot be held on any given day.

Examples:
Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation:
Buy on day 0, sell on day 3 => 310 – 100 = 210
Buy on day 4, sell on day 6 => 695 – 40 = 655
Max Profit = 210 + 655 = 865

Input: prices[] = [4, 2, 2, 2, 4]
Output: 2
Explanation:
Buy on day 3, sell on day 4 => 4 – 2 = 2
Max Profit = 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        int n = prices.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        
        return profit;
    }
};

// Example usage:
// int main() {
//     vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
//     Solution obj;
//     cout << obj.maximumProfit(prices) << endl; // Output: 865
// }
