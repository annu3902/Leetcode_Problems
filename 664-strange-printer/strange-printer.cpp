class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // backward DP version
        for(int i = n-1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i][j-1];
                }else{
                    for(int k = i; k < j; k++){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                    }
                }
            }
        }

        // forward DP version
        // for(int r = 0; r < n; r++){
        //     dp[r][r] = 1;
        //     for(int l = r-1; l >= 0; l--){
        //         if(s[l] == s[r])
        //             dp[l][r] = dp[l+1][r];
        //         else{
        //             for(int k = l; k < r; k++){
        //                 dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
        //             }
        //         }
        //     }
        // }


        return dp[0][n-1];
    }
};