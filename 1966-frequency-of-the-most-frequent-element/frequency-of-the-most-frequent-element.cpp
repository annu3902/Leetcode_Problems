class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long left = 0, right= 0, n = nums.size();
        long ans = 0;
        long sum = 0;
        sort(nums.begin(), nums.end());

        for(; right  < n; right++){
            // Adding element from right It may make the window invalid
            sum = sum + nums[right];

            for(; nums[right]*(right - left + 1) - sum > k; left++){
                // Remove element to make the window again valid
                sum = sum -nums[left];
            }
            // Length of Valid Window
            long length = right - left + 1;
            ans = max(ans, length);
        }
        return ans;
    }
};