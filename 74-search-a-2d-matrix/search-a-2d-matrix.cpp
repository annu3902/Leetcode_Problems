class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;
        int low = matrix[0][0];
        int high = matrix[m-1][n-1];
        while(row < m && col >= 0){
            if(target <= matrix[row][col]){
                for(int i=0; i<n; i++){
                    if(matrix[row][i] == target) return true;
                }
                return false;
            }

            if(target > matrix[row][col]){
                row++;
            }
        }
        return false;
    }
};