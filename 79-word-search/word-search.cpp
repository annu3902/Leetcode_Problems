class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        bool ans=0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == word[0]){
                   cout<<"Hii";
                   ans = ans || solve(board,i,j,word,0);
                }
                // cout<<board[i][j]<<" ";
            }
        }
        return ans;
    }

    private:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    bool solve(vector<vector<char>>&board, int i, int j, string &word, int index){

        int m=board.size();
        int n=board[0].size();
        if(index >= word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='*') return false;
        if(board[i][j] != word[index]) return false;

        board[i][j] = '*'; // It means that block is already visited

        bool ans=0;
        for(int k=0; k<4; k++){
           ans = ans || solve(board, i+row[k], j+col[k], word, index+1);
        }
        board[i][j] = word[index];
        return ans;
    }
};