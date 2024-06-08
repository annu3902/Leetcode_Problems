class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Using the remainder map for checking

        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            int remainder = prefixSum[i] % k;

            if(remainder==0 && i + 1 >= 2) return true;

            else if(mp.count(remainder)){
                int index = mp[remainder];
                if(i-index >= 2) return true;
            }
            
            if(mp.count(remainder) == 0)
                mp[remainder] = i;
        }

        return false;

    }
};