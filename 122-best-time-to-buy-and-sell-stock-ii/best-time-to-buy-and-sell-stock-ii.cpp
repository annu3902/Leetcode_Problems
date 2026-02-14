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
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // // dp[i][1] ->  max profit generate by giving the option to buy the ith stock
        // // dp[i][0] -> max profit generate by not giving the option to buy ith stock

        // dp[n][0] = dp[n][1] = 0;

      
        int flag = 0; // it tells if i have the choice to buy the stock or not
        int cost1 = 0;
        int cost2 = 0;

        for(int i=n-1; i>=0; i--){
            int profit = 0;
            for(int j=0; j<=1; j++){
                if(j == 1){
                   profit = max(-prices[i] + cost1, 0 + cost2);
                   cost2 = profit;
                }
                else{
                    profit = max(prices[i] + cost2, 0 + cost1);
                    cost1 = profit;
                }
            }           
        }

        return cost2;
    }

};