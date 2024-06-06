class Solution {
public:
int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, 0, sizeof(dp));

        // dp[i][j] -> Longest Common Subsequence ending at length i at string 1 and j at string 2

        /*Base Case
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;*/

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }

        }
        return dp[n][n];

    }

    // bbbab -> bab
    // babbb -> bab --> LCS between the string and its reverse
};