class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(mpp.count(target - nums[i])){
                return {i, mpp[diff]};
            }
            mpp[nums[i]] = i;
        }
        

        return {-1,-1};
    }
};