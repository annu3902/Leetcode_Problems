class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =nums.size();
        if(n == 1) return 0;
        if(n == 2) {
          int ans  = (nums[0] > nums[1]) ? 0 :1;
          return ans; 
        }

        int low = 1;
        int high = n-2;
        int mid;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]){
                return mid;
            }

            else {
                if(nums[mid] > nums[mid - 1]){
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        if(nums[0] > nums[1]) return 0;
        else{
            return n-1;
        }
    }
};