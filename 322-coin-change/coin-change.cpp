class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(begin(coins), end(coins));
        reverse(begin(coins), end(coins));

        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }

        for(int j=1; j*coins[0]<=amount; j++){
            dp[0][coins[0]*j] = j;
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                int notPick = dp[i-1][j];
                int pick = (j >= coins[i]) ? 1 + dp[i][j - coins[i]] : 1e9;

                dp[i][j] = min(pick, notPick);
            }
        }

        if(dp[n-1][amount] != 1e9) return dp[n-1][amount];
        return -1;
    }
};