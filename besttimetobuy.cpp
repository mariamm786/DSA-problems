class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0; // No transaction possible with less than 2 prices

        int bestbuy = prices[0]; // Initialize with the first day's price
        int maxprofit = 0;

        for (int i = 1; i < n; i++) {
            // Update the best day to buy
            bestbuy = min(bestbuy, prices[i]);

            // Calculate the profit for selling on the current day
            int currprofit = prices[i] - bestbuy;

            // Update max profit
            maxprofit = max(maxprofit, currprofit);
        }

        return maxprofit;
    }
};
