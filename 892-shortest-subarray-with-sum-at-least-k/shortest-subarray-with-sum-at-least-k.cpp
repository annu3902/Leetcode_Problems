class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int64_t prfSum[100001], dq[100001], lo = 0, hi = 0, n = nums.size(), k64 = k, ret = INT_MAX;
        for (int64_t i = prfSum[0] = 0; i < n; i++) prfSum[i + 1] = (prfSum[i] + nums[i]);
        for (int64_t i = 0; i <= n; i++) {
            while (lo < hi && ((prfSum[i] - prfSum[dq[lo]]) >= k64)) ret = min(ret, i - dq[lo++]);
            while (lo < hi && (prfSum[i] <= prfSum[dq[hi - 1]])) hi--;
            dq[hi++] = i;
        }
        if (ret == INT_MAX) return -1; else return ret;
    }
};