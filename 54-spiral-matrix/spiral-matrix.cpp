class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int start_row = 0;
        int start_col = 0;
        int end_row = m - 1;
        int end_col = n - 1;

        while (start_row <= end_row && start_col <= end_col) {
            // Traverse right
            for (int j = start_col; j <= end_col; j++) {
                ans.push_back(matrix[start_row][j]);
            }
            start_row++;

            // Traverse down
            for (int i = start_row; i <= end_row; i++) {
                ans.push_back(matrix[i][end_col]);
            }
            end_col--;

            // Traverse left
            if (start_row <= end_row) {
                for (int j = end_col; j >= start_col; j--) {
                    ans.push_back(matrix[end_row][j]);
                }
                end_row--;
            }

            // Traverse up
            if (start_col <= end_col) {
                for (int i = end_row; i >= start_row; i--) {
                    ans.push_back(matrix[i][start_col]);
                }
                start_col++;
            }
        }

        return ans;
    }
};