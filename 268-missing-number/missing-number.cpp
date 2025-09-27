class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int ans = n * (n + 1)/2;

        int sum = accumulate(begin(nums), end(nums), 0);

        return (ans - sum);
    }
};