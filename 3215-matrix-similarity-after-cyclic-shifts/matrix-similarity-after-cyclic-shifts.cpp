class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k % m;
        
        for(int i =0; i<=n-1; i++){
            for(int j =0; j<m/2; j++){
                if(mat[i][j] != mat[i][(j + k) % m]){
                    // cout<<"false";
                    return false;
                }
            }
        }
        return true;
    }
};