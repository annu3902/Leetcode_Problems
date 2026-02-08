class Solution {
private:
    bool dfs(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;

        if(j < 0) return false;

        if(i < 0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = dfs(i-1, j-1, s, p, dp);
        }
        
        else if(p[j] == '*'){
            for(int k=i; k>=0; k--){
                if(dfs(k-1, j, s, p, dp) == true) return dp[i][j] = true;
            }
            return dp[i][j] = dfs(i, j-1, s, p, dp);
        }
        
        return dp[i][j] = false;

    }

public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<int> prev (n+1, 0);
        vector<int> curr(n+1, 0);
        prev[0] = 1;

        for(int j=1; j<=n; j++){
            if(p[j-1] != '*') break;
            prev[j] = 1;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }

                else if(p[j-1] == '*'){
                    
                    curr[j] = curr[j-1] || prev[j];
                }
            }
            prev = curr;
            curr.assign(n+1, 0);
        }
        return prev[n];
    }
};