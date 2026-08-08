class Solution {
public:
    bool candyAllocationPossible(vector<int>& nums, long long maxCandy, long long k){
        int n = nums.size();
        long long childrenCount = 0;

        for(int i=0; i<n; i++){
            childrenCount += (nums[i]/maxCandy);
            if(childrenCount >= k) return true;
        }

        return false;    
    }
    
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        // long long totalCandies = accumulate(begin(nums), end(nums), 0);
        long long totalCandies = 0;
        for(int i=0; i<n; i++){
            totalCandies += nums[i];
        }

        if(totalCandies < k) return 0;

        long long left = 1;
        long long right = totalCandies;
        int ans = 0;

        while(left <= right){
            long long mid = left + (right - left)/2;

            if(candyAllocationPossible(nums, mid, k)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid-1;
            }
        }    

        return ans;        
    }
};