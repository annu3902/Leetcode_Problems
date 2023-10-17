class Solution {
public:
    void helper(int num, int ind, int k, int n, vector<int> & subset, vector<vector<int>> &ans){
        if(subset.size() == k){ans.push_back(subset); return;}

        if(ind == n) return;

        subset.push_back(num);
        helper(num +1, ind +1, k, n, subset, ans);

        subset.pop_back();
        helper(num +1, ind +1, k, n, subset, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        vector<vector<int>> ans;

        helper(1, 0, k, n, subset, ans);
        return ans;
    }
};