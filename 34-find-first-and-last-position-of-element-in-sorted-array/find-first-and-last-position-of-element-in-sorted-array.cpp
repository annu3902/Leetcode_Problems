class Solution {
private:
    int findStart(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] > target){
                end = mid - 1;
            }else if (nums[mid] < target){
                start = mid + 1;
            }else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }

    int findEnd(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] > target){
                end = mid - 1;
            }else if (nums[mid] < target){
                start = mid + 1;
            }else {
                ans = mid;
                start = mid + 1;
            }
        }

        return ans;
    }



public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int start = findStart(nums, target);
        int end = findEnd(nums, target);

        return {start, end};
    }
};