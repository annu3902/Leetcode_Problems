class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0;
        int cnt =0;
        int n =nums.size();
        map<int, int> mpp;
        mpp[sum] =1;

        for(int i =0; i<n; i++)
        {
            sum += nums[i];
            if(mpp.find(sum - k) != mpp.end())
            {
                cnt += mpp[sum - k];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};