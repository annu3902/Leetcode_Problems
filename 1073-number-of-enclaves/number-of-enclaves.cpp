class Solution {
private:
    vector<int> neighbour = {-1, 0, 1, 0, -1};
    void dfs(int x, int y, vector<vector<int>>& matrix){
        matrix[x][y] = -1;

        for(int i=0; i<4; i++){
            int nx = x + neighbour[i];
            int ny = y + neighbour[i+1];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            else if(matrix[nx][ny] == 1){
                dfs(nx, ny, matrix);
            }
        }
        return;
    }

public:
    int m, n;
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> matrix = grid;
        m = matrix.size();
        n = matrix[0].size();

        // Boundary Traversal
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 1){
                dfs(i, 0, matrix);
            }
            if(matrix[i][n-1] == 1){
                dfs(i, n-1, matrix);
            }
        }

        for(int i=0; i<n; i++){
            if(matrix[0][i] == 1){
                dfs(0, i, matrix);
            }
            if(matrix[m-1][i] == 1){
                dfs(m-1, i, matrix);
            }
        }
        int cnt=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<matrix[i][j]<<" ";
                if(matrix[i][j] == 1){
                    cnt++;
                }
            }
            cout<<endl;
        }
        return cnt;
    }
};