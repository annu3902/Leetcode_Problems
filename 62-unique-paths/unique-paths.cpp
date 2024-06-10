class Solution {
public:
int dp[101][101];
    int uniquePaths(int m, int n) {
        memset(dp, 0, sizeof(dp));

        dp[m-1][n-1] = 1;
        for(int i = m-1; i >= 0; i--){

            for(int j=n-1; j >= 0; j--){
                if(j+1<n || i+1<m){
                    dp[i][j] = dp[i][j+1] + dp[i+1][j];
                }
            }

        }

        return dp[0][0];
        
    }

    int dfs2(int m, int n, int i, int j){

        if(i==0 && j==0) return 1;

        if((i < 0 && j>0) || (j < 0 && i > 0)) return 0;

        int up = dfs2(m, n, i-1, j);
        int left = dfs2(m, n, i, j-1);

        return up + left;

    }

    int dfs(int m, int n, int i, int j){
        if(i == m-1 && j == n-1) return 1;

        if((i >= m && j < n )|| (i < m && j >= n)) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = dfs(m, n, i, j+1);
        int op2 = dfs(m, n, i+1, j);

        return dp[i][j] = (op1 + op2); 
    }
};