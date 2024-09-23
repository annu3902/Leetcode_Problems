class Solution {
public:
    int dfs(int ind, string& s, unordered_set<string>& st, vector<int>& dp){

        if(ind >= s.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int result = 1 + dfs(ind + 1, s, st, dp);

        for(int j=ind; j<s.size(); j++){
            string temp = s.substr(ind, j-ind+1);
            if(st.count(temp)){
                result = min(result, dfs(j+1, s, st, dp));
            }
        }

        return dp[ind] = result;
    }

    int minExtraChar(string s, vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> st (begin(nums), end(nums));
        vector<int> dp(s.size(), -1);

        return dfs(0, s, st, dp);        
    }
};