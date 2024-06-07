class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(begin(wordDict), end(wordDict));
        // Bottom up
        // dp[i] -> i size ka string can be segmented or not from start?
        // dp[0]  -> 0 size ka string can always be segmented;

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] == true && st.count(s.substr(j, i - j))){
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};