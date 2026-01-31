class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string lcs="";

        int i=m;
        int j=n;

        while(i >= 1 && j >= 1){
            if(s1[i-1] == s2[j-1]){
                lcs += s1[i-1];
                i--; j--;
            }

            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }

        reverse(begin(lcs), end(lcs));
        i = 0;
        j = 0;
        int k = 0;

        string ans="";

        while(k < lcs.size()){
            if(s1[i] == s2[j]){
                ans += s1[i];
                i++; j++; k++;
            }else if(s1[i] == lcs[k]){
                ans += s2[j];
                j++;
            }else if(s2[j] == lcs[k]){
                ans += s1[i];
                i++;
            }else{
                ans += s1[i];
                ans += s2[j];
                i++; j++;
            }
        }

        while(i < s1.size()){
            ans += s1[i];
            i++;
        }

        while(j < s2.size()){
            ans += s2[j];
            j++;
        }
        return ans;
    }
};