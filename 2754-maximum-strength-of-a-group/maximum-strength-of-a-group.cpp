class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        int negative = 0;
        int zero = 0;
        int maxi = *max_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());
        for(int x : nums){
            if(x < 0) negative++;
            else if(x == 0) zero++;
            if(x != 0)
                ans *= x;
        }
        if(zero == n) return 0;
if(n > 1 && ans < 0 && (zero == n || zero == n-1)) return 0;

        if(ans < 0 && negative & 1){
            int i = 0;
            while(i < n && nums[i] < 0){
                i++;
            }
            if(n > 1 && nums[i-1 != 0])
                ans/=nums[i-1];
        }
        return ans;
        
    }
};