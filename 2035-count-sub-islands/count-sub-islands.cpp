class Solution {
public:
    //four directions right, left, down, up;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool island) {
        //if out of bounds
        if (i >= grid1.size() || i < 0 || j >= grid1[0].size() || j < 0) return island;
        //if its an ocean or has been visited before
        if (grid2[i][j] == 0 || grid2[i][j] == 2) return island;

        //if there is no land is the first grid
        if (grid1[i][j] != 1) island = false;
        grid2[i][j] = 2; //mark as visited

        //visit the adjacent cells
        for (auto k : dirs) 
            island = dfs(grid1, grid2, i+k[0], j+k[1], island);
        return island;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j, true)) 
                    ans++;
            }
        }

        return ans;
    }
};