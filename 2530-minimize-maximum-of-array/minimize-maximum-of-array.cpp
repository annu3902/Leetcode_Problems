class Solution {
public:
    bool isPossible(vector<int>& nums, int maxElement){
        int n = nums.size();
        long long buffer = 0;

        for(int i=0; i<n; i++){
            // nums[i] -= buffer;
            if(nums[i] - buffer <= maxElement){
                // nums[i] -= buffer;
                buffer += maxElement - nums[i];
            }else{
                return false;
            }
        }

        return true;        
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(begin(nums), end(nums));
        if(maxElement == nums[0]) return maxElement;

        int left = 0;
        int right = maxElement;
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(isPossible(nums, mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};