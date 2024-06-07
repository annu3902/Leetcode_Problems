class Solution {
public:
int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        memset(dp, -1, sizeof(dp));

        return dfs(s, 0, st);

    }

    bool dfs(string s, int index, unordered_set<string> & st){

        if(index >= s.size()) return true;

        if(dp[index] != -1) return dp[index];

        bool ans = false;
        for(int i=index; i<s.size(); i++){
            string temp = s.substr(index, i-index+1);

            if(st.count(temp) && dfs(s, i+1, st)){
                ans = true;
                dp[index] = ans;
                return ans;
            }
        }

        return dp[index] = false;
    }

};