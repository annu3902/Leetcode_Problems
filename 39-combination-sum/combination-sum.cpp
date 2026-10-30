class Solution {
private:
    void dfs(int currPos, int sum, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        else if((sum > target) || (currPos == candidates.size())){
            return;
        }

        temp.push_back(candidates[currPos]);
        dfs(currPos, sum + candidates[currPos], target, candidates, temp, ans);

        temp.pop_back();
        dfs(currPos + 1, sum, target, candidates, temp, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, 0, target, candidates, temp, ans);
        return ans;
    }
};