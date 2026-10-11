class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        int leftMax = 0;
        int rightMax = 0;
        int start = 0;
        int end = n-1;
        int totalWater = 0;

        while(start < end){
            if(nums[start] <= nums[end]){
                int water = leftMax - nums[start];
                if(water > 0){
                    totalWater += water;
                }
                leftMax = max(leftMax, nums[start]);
                start++;
            }

            else{
                int water = rightMax - nums[end];
                if(water > 0){
                    totalWater += water;
                }
                rightMax = max(rightMax, nums[end]);
                end--;
            }
        }

        return totalWater;
    }
};