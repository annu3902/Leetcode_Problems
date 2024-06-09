class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        for(int i = 0; i < n; i++){

            sum += nums[i];

            int remainder = sum % k;
            if(remainder == 0 && i + 1 >= 2) return true;

            else if(mp.count(remainder) && i - mp[remainder] >= 2){
                return true;
            }

            if(mp.count(remainder) == 0){
                mp[remainder] = i;
            }

        }

        return false;

    }
};