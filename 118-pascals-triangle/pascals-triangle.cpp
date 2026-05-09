class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 1; i<numRows; i++){
            vector<int> cols(i+1, 1);
            for(int j = 1; j < i; j++){
                cols[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(cols);
        }
    return ans;
    }
};