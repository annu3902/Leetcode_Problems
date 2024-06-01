class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        solve(n, dp);
        return dp[n];

        // dp[i] -> No. of ways to reach to the ith step
        // dp[0] = 1;
        // dp[1] = 1;

        // for(int i=2; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        return dp[n];
    }

    int solve(int n, vector<int> & dp){
        if(n==0 || n==1) return dp[n] = 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = solve(n-1, dp) + solve(n-2, dp);

        return dp[n];
    }
};