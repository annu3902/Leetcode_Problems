class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& dp, string& s, string& t, vector<vector<int>>& memo){

        if(j == 0) return 1;
        if(i == 0) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int op1 = 0;
        int op2 = 0;
        
        if(s[i-1] == t[j-1]){
            op1 = dfs(i-1, j-1, dp, s, t, memo);
        }

        if(dp[i][j] == dp[i-1][j]){
            op2 = dfs(i-1, j, dp, s, t, memo);
        }
        return memo[i][j] = op1 + op2;
    }

public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m < n) return 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

        return dfs(m, n, dp, s, t, memo);

    }
};