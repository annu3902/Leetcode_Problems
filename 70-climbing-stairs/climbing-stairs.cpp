int value(int destination, vector<int> &dp){
    // Base Case
    if (destination == 0) {
        return 1;
    }
    if(destination<0) return 0;
    // Recurrence Relation
    if(dp[destination] != -1) return dp[destination];
    int tot = value(destination - 1,dp) + value(destination - 2, dp);
    return dp[destination] = tot;
}

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1 , -1);
        return value(n , dp);
    }
};