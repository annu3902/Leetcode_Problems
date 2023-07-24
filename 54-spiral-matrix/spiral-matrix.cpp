

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
            int j = start_col;
            while (j <= end_col) {
                ans.push_back(matrix[start_row][j]);
                j++;
            }
            start_row++;

            // Traverse down
            int i = start_row;
            while (i <= end_row) {
                ans.push_back(matrix[i][end_col]);
                i++;
            }
            end_col--;

            // Traverse left
            if (start_row <= end_row) {
                int j = end_col;
                while (j >= start_col) {
                    ans.push_back(matrix[end_row][j]);
                    j--;
                }
                end_row--;
            }

            // Traverse up
            if (start_col <= end_col) {
                int i = end_row;
                while (i >= start_row) {
                    ans.push_back(matrix[i][start_col]);
                    i--;
                }
                start_col++;
            }
        }

        return ans;
    }
};