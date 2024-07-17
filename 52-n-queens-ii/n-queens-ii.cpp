class Solution {
public:

    int totalNQueens(int n) {
        vector<string> board(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i].push_back('.');
            }
        }

        vector<bool> column(n, 0);
        vector<bool> rightDiagonal(2*n-1, 0);
        vector<bool> leftDiagonal(2*n-1, 0);         
        int cnt = 0;

        dfs(0, n, board, column, rightDiagonal, leftDiagonal, cnt);
        return cnt;
    }

    void dfs(int row, int n, vector<string>& board, vector<bool>& column, vector<bool> &rightDiagonal, vector<bool> &leftDiagonal, int &cnt){
        if(row >= n){
            cnt++;
            return;
        }

        for(int j=0; j<n; j++){
            if(column[j] == 1) continue;
            else if(rightDiagonal[row + j] == 1 || leftDiagonal[j-row+(n-1)] == 1){
                continue;
            }
            else{
                board[row][j] = 'Q';
                column[j] = 1;
                rightDiagonal[row+j] = 1;
                leftDiagonal[j-row+(n-1)] = 1;

                dfs(row+1, n, board, column, rightDiagonal, leftDiagonal, cnt);

                board[row][j] = '.';
                column[j] = 0;
                rightDiagonal[row+j] = 0;
                leftDiagonal[j-row+(n-1)] = 0;
            }
        }
    }
};