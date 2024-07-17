class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0, 0, board);
        return;
    }

    bool check(int num, int i, int j, vector<vector<char>>& board){
        char c = num + '0';
        for(int col=0; col<9; col++){
            if(board[i][col] == c) return false;
        }

        for(int row=0; row<9; row++){
            if(board[row][j] == c) return false;
        }

        int row = (i/3)*3;
        int col = (j/3)*3;

        for(int k=row; k<row+3; k++){
            for(int l = col; l<col+3; l++){
                if(board[k][l] == c) return false;
            }
        }

        return true;
    }

    bool dfs(int i, int j, vector<vector<char>>& board){
        // Base Case
        if(i == 9){
            return true;
        }

        if(j==9){
            return dfs(i+1, 0, board);
        }

        if(board[i][j] != '.'){
            return dfs(i, j+1, board);
        }

        for(int num=1; num<=9; num++){
            if(check(num, i, j, board)){
                board[i][j] = num + '0';
                // Checking for the possibility to fill the other boxes
                if(dfs(i, j+1, board)){
                    return true;
                }
                // If not able to fill other boxes change the number of this box;
                board[i][j] = '.';
            }
        }

        return false;
    }
};