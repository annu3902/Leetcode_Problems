class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        sort(begin(nums), end(nums));
        int maxLength = 1;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            int count = 1;
            if(mp.count(nums[i] - 1)){
                count += mp[nums[i] - 1];
            }
            mp[nums[i]] = count;
            maxLength = max(maxLength, count);
        }
        return maxLength;
    }
};