class Solution {
int dfs(int ind, int optionToBuy, vector<int>& prices, vector<vector<int>>& dp){

    if(ind == prices.size()){
        return 0;
    }

    if(dp[ind][optionToBuy] != -1) return dp[ind][optionToBuy];

    int profit = 0;
    if(optionToBuy == 1){
        profit = max(-prices[ind] + dfs(ind + 1, 0, prices, dp), 0 + dfs(ind + 1, 1, prices, dp));
    }

    else{
        profit = max(prices[ind] + dfs(ind + 1, 1, prices, dp), 0 + dfs(ind + 1, 0, prices, dp));
    }

    return dp[ind][optionToBuy] = profit;
}

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();   
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return dfs(0, 1, prices, dp);
    }
};