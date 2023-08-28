class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n =nums.size();
        sort(nums.begin(), nums.end());
        long int left = 0;
        long int right = 0;
        long int sum = 0;
        long int ans = 0;

        for(; right <n; right++){
            // new element enters and might make the window invalid
            sum += nums[right];
            for(; (right - left + 1)*nums[right] > sum + k; left++){
                // Try to make window valid
                sum -= nums[left];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};