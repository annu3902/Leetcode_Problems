class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return dfs(s, t, m-1, n-1, dp);
    }

    int dfs(string &s, string &t, int m, int n, vector<vector<int>>& dp){
        if(n < 0) return 1;

        if(m < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int take = 0;
        if(s[m] == t[n]){
            int op1 = dfs(s, t, m-1, n-1, dp);
            // int op2 = dfs(s, t, m-1, n);
            take = op1;
        }   

        int notTake = dfs(s, t, m-1, n, dp);

        return dp[m][n] = take + notTake;
    }

};