class Solution {
public:
    vector<int> neighbour = {-1, 0, 1, 0, -1};
    int m, n;

    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = '#';

        for(int i=0; i<4; i++){
            int nx = x + neighbour[i];
            int ny = y + neighbour[i+1];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            else if(board[nx][ny] == 'O'){
                dfs(nx, ny, board);
            }

        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
                        dfs(i, j, board);
                    }
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};