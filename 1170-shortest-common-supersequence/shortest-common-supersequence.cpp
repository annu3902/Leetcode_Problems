class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int col=0; col <= n; col++){
            dp[0][col] = col;
        }

        for(int row = 0; row <= m; row++){
            dp[row][0] = row;
        }

        // dp[i][j] -> shortest Common Super-sequence when the string1 is of length i and the string2 is of length j

        for(int i=1; i <= m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] != s2[j-1]){
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
                else{
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
        }

        string ans="";
        int i=m;
        int j=n;

        while(i > 0 && j > 0){

            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }

            else if(dp[i][j-1] > dp[i-1][j]){
                ans.push_back(s1[i-1]);
                i--;
            }
            else{
                ans.push_back(s2[j-1]);
                j--;
            }

        }

        while(i > 0){
            ans.push_back(s1[i-1]);
            i--;
        }

        while(j > 0){
            ans.push_back(s2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};