class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return dfs(0, 0, board);
    }

    bool dfs(int i, int j, vector<vector<char>>& board){
        // IF crosses the last row it is solvable
        if(i==9) return true;

        if(j==9){
            return dfs(i+1, 0, board);
        }

        if(board[i][j] == '.'){
            return dfs(i, j+1, board);
        }

        char c = board[i][j];
        for(int col=0; col<9; col++){
            if(col == j) continue;
            else if(board[i][col] == c){
                return false;
            }
        }

        for(int row=0; row<9; row++){
            if(row == i) continue;
            if(board[row][j] == c){
                return false;
            }
        }

        int startRow = (i/3)*3;
        int startCol = (j/3)*3;

        for(int row = startRow; row<startRow + 3; row++){
            for(int col =startCol; col<startCol + 3; col++){
                if(row == i && col == j) continue;
                else if(board[row][col] == c) return false;
            }
        }

        // cout<<board[i][j]<<endl;
        // cout<<i<<" "<<j;
        // return true;
        return dfs(i, j+1, board);

    }
};