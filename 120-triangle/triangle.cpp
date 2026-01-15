class Solution {
private:

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        vector<vector<int>> dp;
        for(int i=0; i<m; i++){
            vector<int> temp;
            for(int j=0; j<triangle[i].size(); j++){
                temp.push_back(0);
            }
            dp.push_back(temp);
        }

        for(int i=0; i<triangle[m-1].size(); i++){
            dp[m-1][i] = triangle[m-1][i];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];

    }
};