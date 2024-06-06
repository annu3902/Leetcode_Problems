class Solution {
public:
int dp[2][1001];

    int lcs(string s, string t, int i, int j){
        if(i >= s.size() && j >= t.size()){
            return 0;
        }
        else if(i >= s.size() && j < t.size()) return 0;

        else if(i < s.size() && j >= t.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            int result = 1 + lcs(s, t, i+1, j+1);
            dp[i][j] = result;
            return result;
        }

        int op1 = lcs(s, t, i, j+1);
        int op2 = lcs(s, t, i+1, j);

        return dp[i][j] = max(op1, op2);

    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, 0, sizeof(dp));

        // return lcs(s,t,0,0);

        // dp[i][j] -> Longest Common Subsequence ending at length i at string 1 and j at string 2

        // Base Case
        /*for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;*/
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0); 

        for(int i=1; i<=n; i++){

            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;

        }
        return prev[n];
    }

    // bbbab -> bab
    // babbb -> bab --> LCS between the string and its reverse
};