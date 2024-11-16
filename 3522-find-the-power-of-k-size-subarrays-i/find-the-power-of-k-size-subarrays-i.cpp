class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        std::vector<int> result(nums.size() - k + 1, -1);
        result[0] = nums[k - 1];

        int lastBreak{ -1 };
        for (int i{ 1 }; i < k; ++i) {
            if (nums[i - 1] + 1 != nums[i]) { result[0] = -1; lastBreak = i; }
        }

        for (int i{ k }; i < nums.size(); ++i) {
            if (nums[i - 1] + 1 != nums[i]) lastBreak = i;

            if (i - lastBreak + 1 >= k) result[i - k + 1] = nums[i];
        }

        return result;
    }
};