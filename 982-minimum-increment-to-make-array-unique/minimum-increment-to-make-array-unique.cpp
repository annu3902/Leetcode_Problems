class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int count = 0;
        
        // 1 1 2 2 3 7
        for(int i=1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                count += (nums[i-1] - nums[i] + 1);
                nums[i] = nums[i-1] + 1;
            } 
        }
        
        return count;
    }
};