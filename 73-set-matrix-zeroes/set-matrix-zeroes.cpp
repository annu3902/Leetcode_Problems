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
        // vector<vector<int>> duplicate = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};