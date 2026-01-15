class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // dp[i][j] -> min health requ. to survive at (i, j);
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e8));


        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1){
                    if(dungeon[m-1][n-1] <= 0){
                        dp[m-1][n-1] = abs(dungeon[m-1][n-1]) + 1;
                    }else{
                        dp[m-1][n-1] = 1;
                    }
                }
                else{
                    int op1 = (i+1 <= m-1) ? dp[i+1][j] : 1e8;
                    int op2 = (j+1 <= n-1) ? dp[i][j+1] : 1e8;
                    int minHealth = min(op1, op2);

                    int requiredHealth = minHealth - dungeon[i][j];
                    if(requiredHealth <= 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = requiredHealth;
                    }
                }                
            }
        }
        return dp[0][0];

    }
};