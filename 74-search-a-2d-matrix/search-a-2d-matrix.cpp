class Solution {
public:
    bool binarySearch(vector<int>& nums, int num){
        int n = nums.size();
        // for(int n : nums)cout<<n<<" ";

        int left = 0;
        int right = n-1;
        // int mid=-1;

        while(left <= right){
            int mid = (left + right)/2;

            if(nums[mid] == num) return true;
            else if(num > nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

        return false;

    }

    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();

        int top = 0;
        int bottom = n-1;
        int mid;
        bool flag = false;

        while(top <= bottom){
            mid = (top + bottom)/2;

            if(mid == top && target > nums[mid][m-1]){
                mid = bottom;
                break;
                // break;
            }

            if(target > nums[mid][0]){
                top = mid;
                if(target <= nums[mid][m-1]) break;
            }

            else if(target < nums[mid][0]){
                bottom = mid-1;
            }

            else return true;
        }

        // return binarySearch(nums[mid], target) | ((mid+1 < n) ? binarySearch(nums[bottom], target) : 0);

        return binarySearch(nums[mid], target);

    }
};