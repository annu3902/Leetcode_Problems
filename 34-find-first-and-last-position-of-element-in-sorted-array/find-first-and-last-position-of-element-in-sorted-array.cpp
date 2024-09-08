class Solution {
public:

    int findStart(vector<int>& nums, int target, int start){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] < target){
                low = mid + 1;
            }

            else if(nums[mid] > target){
                high = mid - 1;
            }

            else{
                start = mid;
                high = mid - 1;
                // [8 8 8 8 8]
            }
        }

        return start;
    }

    int findEnd(vector<int>& nums, int target, int end){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] < target){
                low = mid + 1;
            }

            else if(nums[mid] > target){
                high = mid - 1;
            }

            else{
                end = mid;
                low = mid + 1;
                // [8 8 8 8 8]
            }
        }

        return end;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;

        int start = -1;
        int end = -1;
        int n = nums.size();

        int low = 0;
        int high = n-1;

        start = findStart(nums, target, start);
        end = findEnd(nums, target, end);

        result.push_back(start);
        result.push_back(end);

        return result;
    }
};