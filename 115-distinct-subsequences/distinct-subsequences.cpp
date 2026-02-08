class Solution {
private:
    long long dfs(int i, int j, string& s, string& t, vector<vector<long long>>& memo) {

        if(j == 0) return 1;     // formed t completely
        if(i == 0) return 0;     // s finished but t remains

        if(memo[i][j] != -1)
            return memo[i][j];

        long long ans = 0;

        if(s[i-1] == t[j-1]) {
            ans += dfs(i-1, j-1, s, t, memo);  // take
        }

        ans += dfs(i-1, j, s, t, memo);        // skip

        return memo[i][j] = ans;
    }

public:
    int numDistinct(string s, string t) {

        int m = s.size();
        int n = t.size();

        vector<vector<long long>> memo(m+1, vector<long long>(n+1, -1));

        return dfs(m, n, s, t, memo);
    }
};
