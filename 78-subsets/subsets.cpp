class Solution {
public:
    void subsetGenerator(vector<int> & nums, int ind,  vector<int> &temp, vector<vector<int>> &ans){
        int n = nums.size();
        // Base Case
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        // Processing
        
        // Include
        temp.push_back(nums[ind]);
        subsetGenerator(nums, ind + 1, temp, ans);
        // Exclude
        temp.pop_back();
        subsetGenerator(nums, ind + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subsetGenerator(nums, 0, temp, ans);
        return ans;
    }
};