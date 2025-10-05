class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans = matrix;

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){
                int x = m - j - 1;
                int y = n - i - 1;
                ans[x][y] = matrix[i][j];
            }

        }

        reverse(begin(ans), end(ans));


        matrix = ans;
    }
};