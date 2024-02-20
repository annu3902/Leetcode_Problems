class Solution {
public:


    // Space Optimization
    // int minCostClimbingStairs(vector<int> &cost){
    //     int n=cost.size();
    //     int dp0 = cost[0];
    //     int dp1 = cost[1];

    //     for(int i=2; i<n; ++i){
    //         int ans = min(dp0,dp1) + cost[i];
    //         dp0=dp1;
    //         dp1=ans;
    //     }
    //     return min(dp0, dp1);
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     vector<int> dp(n+1, INT_MAX);
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];

    //     for(int i=2; i<n; ++i){
    //         // dp[i] -->  Minimum cost to reach to the ith step
    //         if(i!=n)
    //         dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    //     }
    //     return dp[n] = min(dp[n-1], dp[n-2]);
    // }


    int f(vector<int> &cost, int n, vector<int> &dp){
        // Base Case
        if(n<0) return 0;
        if(n==0) return dp[n] = cost[0];
        if(n==1) return dp[n] = cost[1];

        if(dp[n]!=-1) return dp[n];

        dp[n] = min(f(cost, n-1, dp), f(cost, n-2, dp)) + cost[n]; 
        return dp[n];
    }

    int minCostClimbingStairs(vector<int> &cost){
        int n=cost.size();
        vector<int> dp(n+1,-1);
        dp[n-1] = f(cost, n-1, dp);
        dp[0] = cost[0];
        dp[1] = cost[1];
        return min(dp[n-1], dp[n-2]);
    }
};