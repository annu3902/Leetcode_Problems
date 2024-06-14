class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // dp[i][j] -> minimum number of operations required to convert string 1 of length i and string2 of length j.

        for(int col=0; col <= n; col++){
            dp[0][col] = col;
        }

        for(int row=0; row <= m; row++){
            dp[row][0] = row;
        }

        for(int i=1; i <= m; i++){
            for(int j=1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }

                else{
                    int op1 = 1 + dp[i][j-1];
                    int op2 = 1 + dp[i-1][j-1];
                    int op3 = 1 + dp[i-1][j];

                    dp[i][j] = min({op1, op2, op3});
                }

            }
        }

        return dp[m][n];
        
        
        // dp[i][j] -> minimum number of operations required to convert string1 of length i to string2 of length j.

        // return solve(word1, word2, m, n);
    }

    // Top to down Recursion
    /*int dfs(string &word1, string &word2, int i, int j){

        if(i == word1.length() && j == word2.length()) return 0;

        else if(j == word2.size()) return (word1.size()-i);

        else if(i == word1.size()) return (word2.size()-j);

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

        if(n == 0 || m == 0) return m + n;

        if(dp[m][n] != -1) return dp[m][n];

        if(word1[m-1] == word2[n-1]) return solve(word1, word2, m-1, n-1);

        int op1 = 1 + solve(word1, word2, m, n-1);

        int op2 = 1 + solve(word1, word2, m-1, n-1);

        int op3 = 1 + solve(word1, word2, m-1, n);

        return dp[m][n] = min({op1, op2, op3});

    }*/

};