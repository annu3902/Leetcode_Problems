class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> mini(m, INT_MAX);
        unordered_map<int, int> mp;

        for(int row=0; row<m; row++){
            int j = 0;
            for(int col=0; col<n; col++){
                if(mini[row] > matrix[row][col]){
                    mini[row] = matrix[row][col];
                    j = col;
                }
            }
            mp[mini[row]] = j;
        }

        vector<int>ans;

        for(auto it : mp){
            int element = it.first;
            int col = it.second;
            int maxi =INT_MIN;
            for(int row=0; row<m; row++){
                maxi = max(maxi, matrix[row][col]);
            }
            if(maxi == element) ans.push_back(element);
        }

        return ans;
    }
};