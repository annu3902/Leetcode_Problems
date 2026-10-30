class Solution {
private:
    void dfs(int currPos, int sum, int target, vector<int>& temp, vector<int>& candidates, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        if((sum > target) || (currPos == candidates.size())){
            return;
        }

        for(int i=currPos; i<candidates.size(); i++){
            if(i != currPos && candidates[i] == candidates[i - 1])continue;

            temp.push_back(candidates[i]);
            dfs(i+1, sum + candidates[i], target, temp, candidates, ans);

            temp.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(0, 0, target, temp, candidates, ans);
        return ans; 
    }
};