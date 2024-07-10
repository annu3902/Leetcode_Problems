class NumMatrix {
public:
vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixSum = matrix;
        for(int i=0; i<prefixSum.size(); i++){
            for(int j=1; j<prefixSum[0].size(); j++){
                prefixSum[i][j] += prefixSum[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int ans = 0;
        for(int i=row1; i<=row2; i++){
            if(col1 == 0) ans += prefixSum[i][col2];
            else ans += prefixSum[i][col2] - prefixSum[i][col1 - 1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */