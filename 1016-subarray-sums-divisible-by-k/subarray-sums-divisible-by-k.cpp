class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix = nums;
        for(int i=1; i<n; i++){
            prefix[i] += prefix[i-1];
        }

        int result = 0;
        unordered_map<int, int> mp;

        mp[0] = 1;
        for(int i=0; i<n; i++){
            int rem = prefix[i] % k;

            if(rem < 0) rem += k;
            if(mp.count(rem)){
                result += mp[rem];
            }

            mp[rem]++;
        }
        return result;
    }
};