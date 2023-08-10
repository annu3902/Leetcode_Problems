class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int n = nums.size();
        int low =0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target || nums[low] == target || nums[high] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                // Trimming down the search space
                low = low+1;
                high = high -1;
                continue;
            }

            // Left Sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    //element exist
                    high = mid-1;
                }
                    // element does not exist
                else{
                    low = mid+1;
                }
            }

            // Right Sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high =mid-1;
                }
            }
        }
        return false;
    }
};