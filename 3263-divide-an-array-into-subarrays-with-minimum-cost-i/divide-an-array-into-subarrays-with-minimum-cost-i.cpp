class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n =nums.size();
        int mini = 1e9;

        for(int i = 1; i < n; i++){
            // Forming subarrays pairs
            for(int j = i + 1; j < n; j++){
                mini = min (mini, nums[0] + nums[i] + nums[j]);
            }
        }
        return mini;
    }
};