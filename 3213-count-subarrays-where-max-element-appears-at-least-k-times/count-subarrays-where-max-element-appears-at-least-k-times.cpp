class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        // number of subarrays having count of maximum element greater than or equals to k;

        int n=nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());

        int cnt_max = 0;

        int i=0;
        int j=0;

        while(j < n){

            if(nums[j] == maxElement) cnt_max++;

            while(cnt_max == k){
                result += (n - j); // ans update
                
                // slide the window
                if(nums[i] == maxElement) cnt_max--;
                i++;
            }

            j++;

        }

        return result;
    }
};