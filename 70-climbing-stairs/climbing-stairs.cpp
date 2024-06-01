class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // solve(n, dp);
        // return dp[n];

        // dp[i] -> No. of ways to reach to the ith step
        // dp[0] = 1;
        // dp[1] = 1;

        // for(int i=2; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        // return dp[n];


        // Solution 3
        return solve2(0, n, dp);
    }

    // Recursion for going down

    // int solve(int n, vector<int> & dp){ 
    //     if(n==0 || n==1) return dp[n] = 1;

    //     if(dp[n] != -1) return dp[n];

    //     dp[n] = solve(n-1, dp) + solve(n-2, dp);

    //     return dp[n];
    // }
    

    // Recursion for coming up
    int solve2(int i, int n, vector<int> &dp){

        if(i == n) return dp[i] = 1;
        else if(i > n) return 0;

        else if(dp[i] != -1) return dp[i];

        dp[i] = solve2(i+1, n, dp) + solve2(i+2, n, dp);
        return dp[i];
    }
};