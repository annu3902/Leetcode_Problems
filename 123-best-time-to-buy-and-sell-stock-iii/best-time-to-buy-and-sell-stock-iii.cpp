class Solution {
private:
    int dfs(int i, int optionToBuy, int noOfTransaction, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(noOfTransaction == 0) return 0;

        if(i == prices.size()) return 0;

        if(dp[i][optionToBuy][noOfTransaction] != -1) return dp[i][optionToBuy][noOfTransaction];

        int profit = 0;
        if(optionToBuy == 1){
            profit = max((-prices[i] + dfs(i+1, 0, noOfTransaction, prices, dp)), (0 + dfs(i+1, 1, noOfTransaction, prices, dp)));
        }

        else{
            profit = max((prices[i] + dfs(i+1, 1, noOfTransaction-1, prices, dp)), (0 + dfs(i+1, 0, noOfTransaction, prices, dp)));
        }

        return dp[i][optionToBuy][noOfTransaction] = profit;

    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        return dfs(0, 1, 2, prices, dp);

        // for(int i=0; i<=1; i++){
        //     for(int j=0; j<=1; j++){
        //         dp[n][i][j] = 0;
        //     }
        // }

        // // k -> No. of transactions
        // // dp[ind][j][k] -> max profit that can be achieved from index i by having the option to take as j and k transactions remaining

        // for(int i=n-1; i>=0; i--){
        //     for(int j=0; j<=1; j++){
        //         for(int k=1; k<=2; k++){
        //             if(j == 1){
        //                 dp[i][j][k] = max({-prices[i] + dp[i+1][0][k], 0 + dp[i+1][1][k]});
        //             }

        //             else{
        //                 dp[i][j][k] = max({prices[i] + dp[i+1][1][k-1], 0 + dp[i+1][0][k]});
        //             }
        //         }
        //     }
        // }

        // return max(dp[0][1][1], dp[0][1][2]);
    }
};