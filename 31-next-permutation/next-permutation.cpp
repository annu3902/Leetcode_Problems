class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int flag = -1;

        for(int i=n-1; i>=1; i--){
            if(nums[i-1] < nums[i]){
                flag = i-1;
                break;
            }
        }

        
        if(flag == -1){
            reverse(begin(nums), end(nums));
            return;
        }

        for(int i=n-1; i>flag; i--){
            if(nums[i] > nums[flag]){
                swap(nums[i], nums[flag]);
                reverse(nums.begin() + flag + 1, nums.end());
                break;
            }
        }

    }
};