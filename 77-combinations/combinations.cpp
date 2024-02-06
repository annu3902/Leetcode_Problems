class Solution {
private : 
    void solve(int ind, vector<int> &temp, vector<vector<int>> &ans, int k, int n){
        // Base Case
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        // Processing
        for(int i = ind; i <= n; i++){
            temp.push_back(i);
            solve(i + 1, temp, ans, k, n);
            temp.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, temp, ans, k, n);
        return ans;
    }
};