class Solution {
private:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j < 0 && i < 0) return 0;
        if(i < 0) return 1 + dfs(i, j-1, s, t, dp);
        if(j < 0) return 1 + dfs(i-1, j, s, t, dp);

        if(dp[i][j] != -1) return dp[i][j];

        int ins = 0, del = 0, rep = 0;
        if(s[i] == t[j]){
            return dp[i][j] = dfs(i-1, j-1, s, t, dp);
        }
        
        else{
            ins = 1 + dfs(i, j-1, s, t, dp);
            del = 1 + dfs(i-1, j, s, t, dp);
            rep = 1 + dfs(i-1, j-1, s, t, dp);
        }
       
        return dp[i][j] = min({ins, del, rep});
    }

public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // dp[i][j] -> Min. no of operations required to convert s[0..i] to t[0..j];

        for(int j=0; j<=n; j++){
            dp[0][j] = j;
        }

        for(int i=0; i<=m; i++){
            dp[i][0] = i;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int ins = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int rep = 1 + dp[i-1][j-1];

                    dp[i][j] = min({ins, del, rep});
                }
            }
        }
        return dp[m][n];
    }
};