class Solution {
private:
    int f(int amount, vector<int> &coins, vector<int> &dp){
        int n = coins.size();
        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;

        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for(int i =0; i<n; i++){
            int ans = f(amount-coins[i], coins, dp);
            mini = min(mini, ans);
        }
            if(mini != INT_MAX){
                mini += 1;
            }
        return dp[amount] = mini;
    }

    int fTab(vector<int> &coins, int amount){
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int x: coins){
                if(i - x >= 0 && dp[i - x] != INT_MAX)
                dp[i] = min(dp[i - x], dp[i]);
            }
            if(dp[i] != INT_MAX){
                dp[i] += 1;
            }
        }

        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1, -1);
        int ans = fTab(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};