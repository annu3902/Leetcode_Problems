class Solution {
public:
    void helper(vector<int> &candidates, int target, int ind, vector<int> &subset, vector<vector<int>> &ans){
        if(target == 0) {
            ans.push_back(subset);
            return;
        }

        if( ind >= candidates.size() || candidates[ind] > target ) return;

        subset.push_back(candidates[ind]);
        helper(candidates, target - candidates[ind], ind, subset, ans);

        subset.pop_back();
        helper(candidates, target, ind + 1, subset, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        vector<vector<int>> ans;
        helper(candidates, target, 0, subset, ans);
        return ans;
    }
};