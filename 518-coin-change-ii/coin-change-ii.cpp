class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i][j] -> no. of ways to make an amount j;

        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int j=1; j*coins[0]<=amount; j++){
            dp[0][coins[0]*j] = 1;
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                long long pick = (j >= coins[i]) ? (dp[i][j - coins[i]] % INT_MAX) : 0;
                long long notPick = dp[i-1][j] % INT_MAX;

                dp[i][j] = (pick + notPick) % INT_MAX;
            }
        }

        return dp[n-1][amount];
    }
};