class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n-1;

        while(left < right){

            int mid = left + (right - left)/2;

            if(nums[mid] > nums[(mid-1 + n) % n] && nums[mid] > nums[(mid+1 + n) % n]){
                return mid;
            }

            else if(nums[mid] < nums[(mid+1 + n) % n]){
                left = mid + 1;
            }

            else{
                right = mid;
            }
        }

        return right;
    }
};