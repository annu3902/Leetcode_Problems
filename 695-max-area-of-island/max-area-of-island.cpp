class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        // 1 -> grid[0][1]

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){   
                int currNode = grid[i][j];
                if(currNode == 1){
                    int area = dfs(i, j, grid, m, n, directions);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    int dfs(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &directions){
        int area = 1;

        grid[i][j] = 2; // grid[i][j] is visited
        
        for(vector<int> &direction : directions){

            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1){
                area += dfs(new_i, new_j, grid, m, n, directions);
            }
        }
        return area;
    }
};