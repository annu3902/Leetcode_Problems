class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 1;
        for(; right<nums.size(); right++){
            if(nums[right] != 0 && nums[left] == 0){
                swap(nums[left], nums[right]);
            }
            while(left < right && nums[left] != 0){
                left++;
            }
        }

    }
};