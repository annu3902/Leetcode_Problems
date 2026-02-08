class Solution {
private:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp){

        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i-1] == t[j-1]){
            ans += dfs(i-1, j-1, s, t, dp);
        }

        ans += dfs(i-1, j, s, t, dp);

        return dp[i][j] = ans;
    }

public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // dp[i][j] -> No. of distinct ways to form string t[0..j-1] in string s[0..i-1];
        return dfs(m, n, s, t, dp);
    }
};