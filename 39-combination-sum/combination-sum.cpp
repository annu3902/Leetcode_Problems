class Solution {
private:
    void solve(vector<int>& candidates, int ind, vector<int>& temp, int sum,
               int target, vector<vector<int>>& ans) {
        // Base Case
        if (sum > target || ind >= candidates.size()) {
            return;
        }
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        // Processing
        sum += candidates[ind];
        temp.push_back(candidates[ind]);
        solve(candidates, ind, temp, sum, target, ans);
        sum -= candidates[ind];
        temp.pop_back();
        solve(candidates, ind + 1, temp, sum, target, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, 0, temp, 0, target, ans);
        return ans;
    }
};