class Solution {
public:
    vector<vector<int>> dp;

    int fun(vector<int>& prices, int n, int i, int k) {
        if (i == n) {
            return 0;
        }

        if (k == 0) {
            return 0;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        if (k == 2) {
            int c1 = fun(prices, n, i + 1, k - 1) - prices[i];
            int c2 = fun(prices, n, i + 1, k);

            return dp[i][k] = max(c1, c2);
        }
        else {
            int c1 = fun(prices, n, i + 1, k - 1) + prices[i];
            int c2 = fun(prices, n, i + 1, k);

            return dp[i][k] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;

        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));

        int gain = fun(prices, n, 0, k);

        return gain;
    }
};