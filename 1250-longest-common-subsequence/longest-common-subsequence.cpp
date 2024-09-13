class Solution {
public:
    int dfs(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return 1 + dfs(i-1, j-1, text1, text2, dp);
        }

        return dp[i][j] = max(dfs(i-1, j, text1, text2, dp), dfs(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        return dfs(m-1, n-1, text1, text2, dp);
    }
};