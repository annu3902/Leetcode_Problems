class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        visited[i][j] = true;

        vector<vector<int>> neighbours{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(auto &neighbour : neighbours){
            int x = neighbour[0] + i;
            int y = neighbour[1] + j;

            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;

            else if(grid[x][y] == '1' && !visited[x][y]){
                dfs(grid, x, y, visited);
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};