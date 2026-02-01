class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        // dp[i][j] -> Returns if the substring starting from i and ending at j is a palindrome or not
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        // Length 1 string is always a palindrome
        int cntPalindormicSubstring = 0;
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            cntPalindormicSubstring++;
        }

        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                cntPalindormicSubstring++;
            }
        }

        for(int length=3; length<=n; length++){
            for(int start=0; start + length <= n; start++){
                int end = start + length - 1;

                if(s[start] == s[end] && dp[start + 1][end - 1] == 1){
                    dp[start][end] = 1;
                    cntPalindormicSubstring++;
                }else{
                    dp[start][end] = 0;
                }
            }
        }

        return cntPalindormicSubstring;
    }
};