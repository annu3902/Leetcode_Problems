class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n =nums.size();
        int running_maxi =INT_MIN;
        long long score = 0;
        vector<long long > ans(n);
        // vector<int> conver(n);
        for(int i =0; i<n; i++)
        {
            long long conver;
            running_maxi = max(running_maxi, nums[i]);
            conver = nums[i] + running_maxi;
            score += conver;
            ans[i] = score;
        }
        return ans;

    }
};