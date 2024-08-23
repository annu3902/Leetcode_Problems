class Solution {
public:
    int minDifficulty(vector<int>& complexity, int days) {
        int n = complexity.size();
    if (n < days) return -1; // If tasks are fewer than days, it's impossible to split

    vector<vector<long long>> dp(n + 1, vector<long long>(days + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= days; j++) {
            int maxComplexity = 0;
            for (int k = i; k > 0; k--) {
                maxComplexity = max(maxComplexity, complexity[k-1]);
                dp[i][j] = min(dp[i][j], dp[k-1][j-1] + maxComplexity);
            }
        }
    }

    return dp[n][days];
    }
};

// int findMinComplexity() {
   
// }