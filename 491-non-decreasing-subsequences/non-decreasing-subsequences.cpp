class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        solve(nums, 0, temp);
        return ans;
    }

    void solve(vector<int> &nums, int currIndex, vector<int> &temp){
        if(currIndex >= nums.size()){
            if(temp.size() >= 2){
                ans.push_back(temp);
            }
            return;
        }

        // pick
        if(currIndex == 0 || temp.empty() || temp.back() <= nums[currIndex]){
            temp.push_back(nums[currIndex]);
            solve(nums, currIndex+1, temp);
            temp.pop_back();
        }

        // skip
        if(temp.empty() || temp.back() != nums[currIndex]){
            solve(nums, currIndex+1, temp);
        }
        
        return;

    }
};