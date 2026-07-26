class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxi = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(maxi < mp[nums[i]]){
                maxi = mp[nums[i]];
            }
        }

        for(auto it : mp){
            if(it.second == maxi){
                ans += it.second;
            }
        }

        return ans;
    }
};