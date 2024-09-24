class Solution {
public:

    int dfs(int i, string &s, unordered_set<string>& st, vector<int>& dp){

        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int result = 1 + dfs(i-1, s, st, dp);

        for(int j=i; j>=0; j--){
            string temp = s.substr(j, i-j+1);

            if(st.count(temp)){
                result = min(result, dfs(j-1, s, st, dp));
            }
        }

        return dp[i] = result;

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(begin(dictionary), end(dictionary));
        int n = s.size();

        vector<int> dp(n, -1);

        return dfs(n-1, s, st, dp);
    }
};