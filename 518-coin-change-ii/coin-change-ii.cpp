class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // STATE -> NUMBER OF WAYS TO PRODUCE SUM, FROM THE ith INDEX
        vector<vector<int>> dp(n+1, vector<int> (amount+1)); // No of ways to produce sum from 0 to amount by taking the coins form 0th index till the nth index 

        for(int i=0; i<n; ++i){
            dp[i][0]=1; // No of ways to produce sum =0 from any index=1
        }

        // Since the current state dp[i][sum] depends upon the value of dp[i+1][sum] so the limit goes from (n-1) to 0;
        for(int i=n-1; i>=0; i--){
            // dp[i][sum] = dp[i+1][sum] + dp[i][sum-ci];
            for(int sum=1; sum<=amount; sum++){
                // Skipping the ith index
                int skip = dp[i+1][sum];
                // Picking the ith index
                int pick = 0; // if {sum < coins[i]} --> We can not make the sum.
                if(sum >= coins[i])
                pick = dp[i][sum-coins[i]];
                dp[i][sum] = skip+pick; // dp[i][sum] = dp[i+1][sum]+dp[i][sum-ci] :{sum >= ci}
            }
        }
        return dp[0][amount];
    }
};