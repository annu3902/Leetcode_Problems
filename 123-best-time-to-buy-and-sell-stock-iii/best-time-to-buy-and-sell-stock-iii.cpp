class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[ind][transNo][flag] -> Max profit achieved by 1/2 transaction and option to buy
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=0; i<=1; i++){
            for(int j=0; j<=1; j++){
                dp[n][i][j] = 0;
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int k=1; k<=2; k++){
                    if(j == 1){
                        dp[i][j][k] = max({-prices[i] + dp[i+1][0][k], 0 + dp[i+1][1][k]});
                    }

                    else{
                        dp[i][j][k] = max({prices[i] + dp[i+1][1][k-1], 0 + dp[i+1][0][k]});
                    }
                }
            }
        }

        return max(dp[0][1][1], dp[0][1][2]);
    }
};