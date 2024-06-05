class Solution {
public:

    vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> st;
        int n = nums.size();
        if(n == 1) return {};
        vector<int> temp;
        solve(nums, 0, -1, temp, st);

        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
    }

    void solve(vector<int> &nums, int currIndex, int prevIndex, vector<int> temp, set<vector<int>> &st){

        if(currIndex >= nums.size()){
            if(temp.size() >= 2){
                // ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        // Skip
        solve(nums, currIndex+1, prevIndex, temp,st);
        // Pick
        if(prevIndex == -1 || nums[currIndex] >= nums[prevIndex]){
            temp.push_back(nums[currIndex]);
            solve(nums, currIndex+1, currIndex, temp, st);
        }
    }
};