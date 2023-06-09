class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        int sum = 0;
        mpp[0] =1;
        int n=nums.size();
        int cnt =0;

        for(int i=0; i<=n-1; i++)
        {
            sum += nums[i];

            if(mpp.count(sum-k)){
                cnt += mpp[sum-k];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};