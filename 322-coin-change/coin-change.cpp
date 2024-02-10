class Solution {
private:
// Dp Memoization
    int f(int amount, vector<int> &coins, vector<vector<int>> &dp,int index){
        int n = coins.size();
       
        if(amount == 0) return 0;
        if(index>=coins.size()) return 1e9;

        if(dp[index][amount] != -1) return dp[index][amount];

        // int pick = INT_MAX;
        int pick = 1e9;
        if(amount>=coins[index]) pick = 1 + f(amount - coins[index] , coins , dp,index);
        int notpick = f(amount , coins , dp , index+1);
        int mini = min(pick, notpick);
        
        return dp[index][amount] = min(pick , notpick);
    }

// Dp Tabulation
    // int fTab(vector<int> &coins, int amount){
    //     int n = coins.size();
    //     vector<int> dp(amount + 1, INT_MAX);
    //     dp[0] = 0;

    //     for(int i = 1; i < dp.size(); i++){
    //         for(int x: coins){
    //             if(i - x >= 0 && dp[i - x] != INT_MAX)
    //             dp[i] = min(dp[i - x], dp[i]);
    //         }
    //         if(dp[i] != INT_MAX){
    //             dp[i] += 1;
    //         }
    //     }

    //     return dp[amount];
    // }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans = f(amount, coins ,dp, 0);
        if(ans == 1e9) return -1;
        return ans;
    }
};