class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // // Initialize the vector of vector of size n with element 0.
        // vector<vector<int>> ans(n, vector<int>(n,0));

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         int row = j;
        //         int col = n-i-1;
        //         ans[row][col] = matrix[i][j];
        //     }
        // }
        // matrix = ans;


        int n = matrix.size();
        // Form the transpose matrix
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse the vector
        for(int i =0; i<n; i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};