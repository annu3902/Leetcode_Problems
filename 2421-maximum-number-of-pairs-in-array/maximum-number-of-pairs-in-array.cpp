class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i  : nums){
            mp[i]++;
        }

        int pairs = 0;
        int remainder = 0;
        for(auto it : mp){
            int ele = it.first;
            int freq = it.second;

            pairs += (freq/2);
            remainder += freq % 2;
        }

        return {pairs, remainder};
    }
};