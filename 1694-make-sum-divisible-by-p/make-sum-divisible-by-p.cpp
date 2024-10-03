class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int mod = sum % p;
        if (mod == 0) return 0;
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1;
        long long currSum = 0;
        int minLen = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];
            int currMod = currSum % p;
            int target = (currMod - mod + p) % p;
            if (prefixModMap.find(target) != prefixModMap.end()) {
                minLen = min(minLen, i - prefixModMap[target]);
            }
            prefixModMap[currMod] = i;
        }
        return (minLen == nums.size()) ? -1 : minLen; 
    }
};