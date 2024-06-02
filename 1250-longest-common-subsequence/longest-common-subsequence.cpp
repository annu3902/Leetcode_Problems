class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return lcs(s1, 0, s2, 0, dp);
    }

    int lcs(string& s1, int i, string& s2, int j, vector<vector<int>> &dp){

        if(i == s1.size() || j == s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int cnt = 0;
        if(s1[i] == s2[j]){
           cnt = 1 + lcs(s1, i+1, s2, j+1, dp);
           return dp[i][j] = cnt;
        }

        return dp[i][j] = max(lcs(s1, i+1, s2, j, dp), lcs(s1, i, s2, j+1, dp));
    }

};