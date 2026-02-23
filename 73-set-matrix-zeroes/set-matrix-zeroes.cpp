class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row;
        vector<int> col;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int r : row){
            for(int j=0; j<n; j++){
                matrix[r][j] = 0;
            }
        }

        for(int c : col){
            for(int i=0; i<m; i++){
                matrix[i][c] = 0;
            }
        }

        // Space Complexity - O(M + N)
    }
};