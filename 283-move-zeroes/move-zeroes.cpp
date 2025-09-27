class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0; int right = 1;

        for(; right < n; right++){
            if(nums[right] != 0 && nums[left] == 0){
                swap(nums[right], nums[left]);
                left++;
            }
            while(left < right && nums[left] != 0){
                left++;
            }
        }
    }
};