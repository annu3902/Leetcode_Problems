class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int cntIslands = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        // 1 -> grid[0][1]

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){   
                char currNode = grid[i][j];
                if(currNode == '1'){
                    dfs(i, j, grid, m, n, directions);
                    cntIslands++;
                }
            }
        }
        return cntIslands;
    }

    void dfs(int i, int j, vector<vector<char>> &grid, int m, int n, vector<vector<int>> &directions){
        grid[i][j] = 'e';

        
        for(vector<int> &direction : directions){

            int new_i = i + direction[0];
            int new_j = j + direction[1];

            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == '1'){
                dfs(new_i, new_j, grid, m, n, directions);
            }
        }
    }
};