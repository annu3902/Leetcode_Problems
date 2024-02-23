class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> uniquePathdp(m,vector<int>(n,0));
        uniquePathdp[0][0]=1;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i>=1 && obstacleGrid[i][j]!=1) uniquePathdp[i][j] += uniquePathdp[i-1][j];
                if(j>=1 && obstacleGrid[i][j]!=1) uniquePathdp[i][j] += uniquePathdp[i][j-1];
            }
        }
        return uniquePathdp[m-1][n-1];
    }
};