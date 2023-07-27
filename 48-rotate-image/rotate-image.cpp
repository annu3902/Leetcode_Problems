class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> ans(n, vector<int>(n,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int row = j;
                int col = n-i-1;
                ans[row][col] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};