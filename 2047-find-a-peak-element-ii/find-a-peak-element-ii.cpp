class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans(2);
        int maxi = mat[0][0];
        int m = mat.size();
        int n = mat[0].size();
        int i,j;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            {
                if(maxi < mat[i][j]){
                    maxi = mat[i][j];
                    ans = {i,j};
                }
                maxi = max(maxi, mat[i][j]);
            }
        }
        // return{i,j};
        return ans;
    }
};