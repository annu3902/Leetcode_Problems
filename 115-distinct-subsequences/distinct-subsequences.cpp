class Solution {
private:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp){

        if(j < 0) return 1;
        else if(i < 0) return 0;

        else if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;

        if(s[i] == t[j]){
            ans += dfs(i-1, j-1, s, t, dp);
        }

        ans += dfs(i-1, j, s, t, dp);

        return dp[i][j] = ans;
    }

public:
    int numDistinct(string s, string t) {

    int m = s.size();
    int n = t.size();

    vector<vector<double>> dp(m+1, vector<double>(n+1, 0));

    for(int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){

            if(s[i-1] == t[j-1])
                dp[i][j] += dp[i-1][j-1];

            dp[i][j] += dp[i-1][j];
        }
    }

    return dp[m][n];
}
};