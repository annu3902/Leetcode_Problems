class Solution {
public:
int dp[502][502];
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        memset(dp, -1, sizeof(dp));
        // dp[i][j] -> minimum number of operations required to convert string1 of length i to string2 of length j.

        return solve(word1, word2, m, n);
    }

    // Top to down Recursion
    int dfs(string &word1, string &word2, int i, int j){

        if(i == word1.length() && j == word2.length()) return 0;

        else if(j == word2.size()) return 1 + dfs(word1, word2, i+1, j);

        else if(i == word1.size()) return 1 + dfs(word1, word2, i, j+1);

        else if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dfs(word1, word2, i+1, j+1);

        int op1 = 1 + dfs(word1, word2, i, j+1);

        int op2 = 1 + dfs(word1, word2, i+1, j+1);

        int op3 = 1 + dfs(word1, word2, i+1, j);

        return dp[i][j] = min({op1, op2, op3});
        
    }

    // Bottom to up Recursion

    int solve(string &word1, string &word2, int m, int n){

        if(m == 0 && n == 0) return 0;

        if(n == 0) return 1 + solve(word1, word2, m-1, n);

        if(m == 0) return 1 + solve(word1, word2, m, n-1);

        if(dp[m][n] != -1) return dp[m][n];

        if(word1[m-1] == word2[n-1]) return solve(word1, word2, m-1, n-1);

        int op1 = 1 + solve(word1, word2, m, n-1);

        int op2 = 1 + solve(word1, word2, m-1, n-1);

        int op3 = 1 + solve(word1, word2, m-1, n);

        return dp[m][n] = min({op1, op2, op3});

    }

};