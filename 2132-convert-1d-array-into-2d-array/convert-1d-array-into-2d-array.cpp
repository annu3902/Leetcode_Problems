class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> ans;
        if(size != m*n) return ans;

        for(int i=0; i<m; i++){
            vector<int> temp(original.begin()+(n*i), original.begin()+(n*i)+n);
            ans.push_back(temp);
        }
        return ans;
    }
};