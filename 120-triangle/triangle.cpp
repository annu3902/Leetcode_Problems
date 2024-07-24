class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (triangle[m-1].size(), 1e9));

        for(int j=0; j<triangle[m-1].size(); j++){
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                int first = dp[i+1][j];
                int second = dp[i+1][j+1];

                dp[i][j] = min(first, second) + triangle[i][j];
            }
        }

        return dp[0][0];

    }
};