class Solution {
public:
int dp[502][502];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return dfs(word1, word2, 0, 0);
    }

    int dfs(string &word1, string &word2, int i, int j){

        if(i == word1.length() && j == word2.length()) return 0;

        if(j == word2.size()) return 1 + dfs(word1, word2, i+1, j);

        if(i == word1.size()) return 1 + dfs(word1, word2, i, j+1);

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dfs(word1, word2, i+1, j+1);

        int op1 = 1 + dfs(word1, word2, i, j+1);

        int op2 = 1 + dfs(word1, word2, i+1, j+1);

        int op3 = 1 + dfs(word1, word2, i+1, j);

        return dp[i][j] = min({op1, op2, op3});
        
    }

};