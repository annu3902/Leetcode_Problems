class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        // dp[i][j] -> true if Substring s[i..j] is a Palindrome 
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int startInd = 0;
        int maxLength = 0;

        // length 1 substring
        for(int i=0; i<n; i++){
            maxLength = 1;
            startInd = i;
            dp[i][i] = true;
        }

        // length 2 substrng
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                maxLength = 2;
                startInd = i;
                dp[i][i+1] = true;
            }
        }

        // Check from the length 3

        for(int length = 3; length <= n; length++){
            for(int start = 0; start + length <= n; start++){
                int end = start + length - 1;

                if(s[start] == s[end] && dp[start+1][end-1] == true){
                    dp[start][end] = true;
                    startInd = start;
                    maxLength = length;
                }  
            }
        }

        string ans = s.substr(startInd, maxLength);
        return ans;

    }
};