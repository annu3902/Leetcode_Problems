class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n =matrix[0].size();
        vector<vector<int>> ans(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int row = j;
                int col = i;
                ans[row].push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};