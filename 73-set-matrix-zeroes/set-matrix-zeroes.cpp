class Solution {
private:
    void changeMatrix(vector<vector<int>>& matrix, int row, int col){
        for(int j=0; j<matrix[0].size(); j++){
            matrix[row][j] = 0;
        }

        for(int i=0; i<matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> duplicate = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> row;
        unordered_set<int> col;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(duplicate[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto it : row){
            for(int j=0; j<n; j++){
                matrix[it][j] = 0;
            }
        }

        for(int it: col){
            for(int i=0; i<m; i++){
                matrix[i][it] = 0;
            }
        }
    }
};