class Solution {
public:
    // int solve(vector<int> &cost, int n, vector<int> &dp){
        // Recursion + Memoization
    //     if(n < 0) return 0;

    //     if(n == 0){
    //         dp[n] = cost[n];
    //         return dp[n];
    //     }

    //     if(n == 1){
    //         dp[n] = cost[n];
    //         return dp[n];
    //     }

    //     if(dp[n] != -1) return dp[n];

    //     dp[n] = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp)) + cost[n];
    //     return dp[n];
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n, -1);
    //     return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    // }

    int minCostClimbingStairs(vector<int> &cost){
        int n =cost.size();
        int dp0 = cost[0];
        int dp1 = cost[1];

        for(int i=2; i<n; i++){
            int currCost = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = currCost;
        }

        return min(dp0 , dp1);

    }

};