class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int ind = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // return ind;
        int n = nums.size();    
        int low =0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid -1;
            }else if(nums[mid] < target){
                low = mid+1;
            }
        }
        return ans;
    }
};