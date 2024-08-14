class Solution {

    int sliding(int diff, vector<int>& nums) {

        // how many pairs are having absolute difference less than or equal to
        // dif;
        int i = 0;
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {

            while (nums[j] - nums[i] > diff)
                i++;
            count += j - i;
        }

        return count;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // nlog n
        int high = nums[nums.size() - 1] - nums[0];
        int low = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] < low) {
                low = nums[i] - nums[i - 1];
            }
        }

        while (low < high) {
            int mid = (low + high) / 2;
            int ans = sliding(mid, nums); // mid = 5
            // checking that how many pairs are having absolute difference less
            // than or equal to 5;
            if (ans < k) {
                low = mid + 1;
            } else
                high = mid;
        }

        return low;
    }
};