class Solution {
public:
    int f(int amount, vector<int> &coins, vector<int> &dp){
        int totalCoins = coins.size();
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;

        for(int i =0; i <totalCoins; i++){
            int ans = f(amount-coins[i], coins, dp);
            if(ans != INT_MAX){
                mini = min(mini , ans+1);
            }
        }
        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        int totalCoins = coins.size();
        // dp[amount] --> minimum number of coins to produce amount
        vector<int> dp(amount+1 , -1);
        int ans = f(amount, coins, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};