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
        int col0 = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                   if(j == 0){
                        col0 = 0;
                   }
                   else{
                        matrix[0][j] = 0;
                   }
                   matrix[i][0] = 0;
                }
            }
        }

        for(int i=m-1; i>=1; i--){
            for(int j=n-1; j>=1; j--){
                if(matrix[0][j] == 0|| matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=n-1; j>=0; j--){
            if(matrix[0][0] == 0){
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
        

    }
};