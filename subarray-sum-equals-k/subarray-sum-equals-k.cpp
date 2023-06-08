class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        mpp[0] = 1;
        int n =nums.size();
        int cnt =0;
        int sum =0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(mpp.find(sum-k) != mpp.end())
            {
                cnt = cnt + mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};