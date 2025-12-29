class Solution {
public:

int m, n;
void dfs(int x, int y, vector<vector<char>>& board,
         vector<vector<bool>>& visited, bool &flag)
{
    visited[x][y] = true;

    if(x == 0 || x == m-1 || y == 0 || y == n-1){
        flag = true;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + neighbour[i];
        int ny = y + neighbour[i+1];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if(board[nx][ny] == 'O' && !visited[nx][ny]){
            dfs(nx, ny, board, visited, flag);
        }
    }
}

    vector<int> neighbour = {-1, 0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && visited[i][j] == false){
                    bool flag = false;
                    dfs(i, j, board, visited, flag);
                    cout<<i<<" "<<j<<endl;
                    // cout<<flag<<"\n";
                    if(!flag){
                        dfsC(i, j, board);
                    }
                }
            }
        }

        return;
    }

    // void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited, bool& flag){
    //     visited[x][y] = true;

    //     if(board[x][y] == 'O' && (x == 0 || x == m-1 || y == 0 || y == n-1)){
    //         flag = true;
    //     }

    //     for(int i=0; i<4; i++){
    //         int nx = x + neighbour[i];
    //         int ny = y + neighbour[i+1];

    //         if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;

    //         else if(board[nx][ny] == 'O' && visited[nx][ny] == false){
    //             dfs(nx, ny, board, visited, flag);
    //         }

    //         else if(board[nx][ny] == 'O' && visited[nx][ny] == true){
    //             return;
    //         }
    //     }

    // }
    

    void dfsC(int x, int y, vector<vector<char>>& board){
        board[x][y] = 'X';

        // if((x == 0||y == 0||x == board.size() || y == board[0].size()) && board[x][y] == 'O') ;

        for(int i=0; i<4; i++){
            int nx = x + neighbour[i];
            int ny = y + neighbour[i+1];

            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;

            else if(board[nx][ny] == 'O'){
                dfsC(nx, ny, board);
            }
            // else if(board[nx][ny] == 'O' && visited[nx][ny] == true){
            //     return;
            // }
        }

    }
};