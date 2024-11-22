class Solution {
public:
    // Helper function to count uniform rows
    int solve(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int bit = matrix[i][0];
            bool isSame = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != bit) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) ans++;
        }
        return ans;
    }

    // Helper function to flip columns based on a row and target bit
    void update(vector<vector<int>>& matrix, int row, int bit) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[row][j] == bit) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = !matrix[i][j];
                }
            }
        }
    }

    // Main function to calculate the maximum number of equal rows after flips
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = solve(matrix); // Initial count of uniform rows

        for (int i = 0; i < m; i++) {
            int zero = count(matrix[i].begin(), matrix[i].end(), 0); // Count zeros in the row
            if (zero == 0 || zero == n) continue; // Skip if already uniform
            else if (zero < n / 2) {
                update(matrix, i, 0); // Flip columns where value is 0
            } else {
                update(matrix, i, 1); // Flip columns where value is 1
            }
            ans = max(ans, solve(matrix)); // Update maximum uniform rows
        }

        return ans;
    }
};