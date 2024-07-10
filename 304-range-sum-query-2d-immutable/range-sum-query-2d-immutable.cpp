class NumMatrix {
public:
vector<vector<int>> prefixSum;
int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        prefixSum.resize(m+1, vector<int> (n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefixSum[i][j] = matrix[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        ans += prefixSum[row2+1][col2+1] - prefixSum[row2+1][col1] - prefixSum[row1][col2+1] + prefixSum[row1][col1];

        // return prefixSum[row2 + 1][col2 + 1] - prefixSum[row2 + 1][col1] - prefixSum[row1][col2 + 1] + prefixSum[row1][col1];

        // for(int i=0; i<prefixSum.size(); i++){
        //     for(int j=0; j<prefixSum[0].size(); j++){
        //         cout<<prefixSum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;
    }
};

/*
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
*/