class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // No 2 queens must be on same row or coloumn 
        // No 2 Queen be on the same diagonal

        // Filling the board row wise

        vector<vector<string>> result;
        vector<string> board(n);
        for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
                board[i].push_back('.');
           }
        }

        vector<bool> column(n, 0);

        dfs(0, n, board, column, result);
        return result;
    }

    bool checkOnDiagonal(int row, int col, vector<string> &board){
        int i = row;
        int j = col;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        i = row;
        j = col;

        while(i >= 0 && j<board.size()){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void dfs(int row, int n, vector<string> &board, vector<bool> &column, vector<vector<string>> &result){
            // Base Case
            if(row >= n){
                result.push_back(board);
                return;
            }

            for(int col=0; col<n; col++){
                if(column[col] != 0){
                    continue;
                }

                else if(checkOnDiagonal(row, col, board)){
                    board[row][col] = 'Q';
                    column[col] = 1;
                    dfs(row+1, n, board, column, result);

                    // Backtracking
                    board[row][col] = '.';
                    column[col] = 0;                    
                }
            }

        return;
    }
};