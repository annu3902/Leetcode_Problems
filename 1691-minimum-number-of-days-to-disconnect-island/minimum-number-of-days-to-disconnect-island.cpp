class Solution {
public:
    // Function to count the number of islands
    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    // Depth-First Search to mark all connected lands
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return;
        }
        visited[i][j] = 1;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Step 1: Check if the grid is already disconnected
        if (countIslands(grid) != 1) {
            return 0;
        }
        
        // Step 2: Try removing each land cell to see if it disconnects the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        
        // Step 3: If removing one cell doesn't work, try removing two cells
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < m; ++y) {
                            if (grid[x][y] == 1) {
                                grid[x][y] = 0;
                                if (countIslands(grid) != 1) {
                                    return 2;
                                }
                                grid[x][y] = 1;
                            }
                        }
                    }
                    grid[i][j] = 1;
                }
            }
        }
        
        // By this logic, we would always return within the loop,
        // but if not, it would take 2 days at most to disconnect the grid.
        return 2;
    }
};