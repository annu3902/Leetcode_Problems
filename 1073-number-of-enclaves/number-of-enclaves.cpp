class Solution {
public:
    vector<int> neighbour = {-1, 0, 1, 0, -1};
    int m, n;
    void dfs(int x, int y, vector<vector<int>>& matrix){
        matrix[x][y] = 2;

        for(int i=0; i<4; i++){
            int nx = x + neighbour[i];
            int ny = y + neighbour[i+1];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            else if(matrix[nx][ny] == 1){
                dfs(nx, ny, matrix);
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> matrix = grid;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 1 && matrix[i][j] == 1){
                        dfs(i, j, matrix);
                    }
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};