class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //  3-parameters are changing r, c, c
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1e9)));
        
        // Base Case -> For the last row = m-1
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }

        for(int i=m-2; i>=0; i--){

            for(int j1=0; j1<n; j1++){

                for(int j2=0; j2<n; j2++){
                    int maxi = -1e9;
                    
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n)value += dp[i+1][j1+dj1][j2+dj2];
                            else{
                                value += -1e9;
                            }
                            maxi = max(maxi, value);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }

        }

        return dp[0][0][n-1];

    }

    /*int dfs(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){

        // When we out of bound
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;

        // When we attains the destination
        if(i == m-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e9;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += dfs(i+1, j1+dj1, j2+dj2, m, n, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }*/

};