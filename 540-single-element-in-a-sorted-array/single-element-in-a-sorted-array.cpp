class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        for(int i=0; i<=n-2; i++){
            if(i == 0){
                if(nums[i] != nums[i+1])
                    return nums[i];
            }
            else if(nums[i-1] != nums[i] && nums[i+1] != nums[i]){
                return nums[i];
            }
        }
        return nums[n-1];
    }
};