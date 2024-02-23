class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n<2) return triangle[0][0];
        vector<vector<int>> minSumdp(n,vector<int>(n,INT_MAX));

        // dp[k][i] -> minimum path sum till kth row and taking the ith index
        minSumdp[0][0]=triangle[0][0];

        for(int k=1; k<n; ++k){
            for(int i=0; i<=k; ++i){
                int path1 = INT_MAX;
                if(minSumdp[k-1][i] != INT_MAX)
                path1=minSumdp[k-1][i];
                else path1=minSumdp[k-1][i-1];
                
                int path2=INT_MAX;
                if(i>=1)
                    path2=minSumdp[k-1][i-1];
                minSumdp[k][i] = min(path1, path2) + triangle[k][i];
            }
        }

        int miniPathSum = minSumdp[n-1][0];
        for(int x : minSumdp[n-1]){
            miniPathSum = min(miniPathSum, x);
        }
        return miniPathSum;
    }
};