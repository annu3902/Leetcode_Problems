class Solution {
public:
    int MOD = 1e9+7;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<long long>> dp(m+1, vector<long long> (n+1, 0));

        
        // dp[i][j] -> No. of subsequences that can be formed from with the length of i in s and length of j in the string t

        for(int i=0; i<=m; i++){
            dp[i][0] = 1; // if the length of the 2nd string is 0
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                long long take = 0;
                if(s[i-1] == t[j-1]){
                    take = dp[i-1][j-1] % MOD;
                }

                long long notTake = dp[i-1][j] % MOD;
                // dp[i][j] = ((s[i-1] == t[j-1]) ? dp[i-1][j-1] : 0 ) + dp[i-1][j];
                dp[i][j] = (take + notTake) % MOD;
            }
        }

        return dp[m][n];
        

        // return dfs2(s, t, m, n, dp);
    }

    // int dfs2(string& s, string& t, int m, int n, vector<vector<int>>& dp){
    //     if(n == 0) return 1;

    //     if(m == 0) return 0;

    //     if(dp[m][n] != -1) return dp[m][n];

    //     int take = 0;
    //     if(s[m-1] == t[n-1]){
    //         take = dfs2(s, t, m-1, n-1, dp);
    //     }  

    //     int notTake = dfs2(s, t, m-1, n, dp);

    //     return dp[m][n] = take + notTake;
    // }

    // int dfs(string &s, string &t, int m, int n, vector<vector<int>>& dp){
    //     if(n < 0) return 1;

    //     if(m < 0) return 0;

    //     if(dp[m][n] != -1) return dp[m][n];

    //     int take = 0;
    //     if(s[m] == t[n]){
    //         int op1 = dfs(s, t, m-1, n-1, dp);
    //         // int op2 = dfs(s, t, m-1, n);
    //         take = op1;
    //     }   

    //     int notTake = dfs(s, t, m-1, n, dp);

    //     return dp[m][n] = take + notTake;
    // }

};