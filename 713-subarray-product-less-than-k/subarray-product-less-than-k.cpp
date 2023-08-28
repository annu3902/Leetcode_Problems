class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long product = 1;
        int left = 0;
        int right = 0;
        int ans = 0;

        for(right = 0; right < n; right++){
            product *= nums[right];
            for(; product >= k && left <= right; left++){
                product /= nums[left];
            }
            int length = (right - left + 1);
            ans += length;
        }
        return ans;
    }
};