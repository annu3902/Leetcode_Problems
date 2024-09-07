class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Find the breakpoint
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        // cout<<ind<<" ";

        if(ind == -1){
            reverse(begin(nums), end(nums));
            return;
        }

        // Find the number just greater than the nums[ind]
        for(int i=n-1; i>ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // arrange the remaining in the sorted order
        reverse(nums.begin()+ind+1, nums.end());
    }
};