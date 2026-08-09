class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSize = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0){
                    maxSize = max(maxSize, dp[i][j]);
                }

                else if(matrix[i][j] == '1') {
                    dp[i][j] = dp[i][j] + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }

        return maxSize * maxSize;
    }
};