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
            // return dfs(i-1, j, s, p, dp) || dfs(i, j-1, s, p, dp);
        }
        
        return dp[i][j] = false;

    }

public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m-1, n-1, s, p, dp);
    }
};