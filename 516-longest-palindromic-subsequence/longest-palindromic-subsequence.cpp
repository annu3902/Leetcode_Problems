class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j] -> Length of Loongest Palindromic Subsequence in substring s[i...j]
        //  Base Case
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }

        for(int length=2; length <= n; length++){
            for(int i=0; i + length <= n; i++){
                int j = i + length - 1;

                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }

            }
        }

    return dp[0][n-1];
    }
};