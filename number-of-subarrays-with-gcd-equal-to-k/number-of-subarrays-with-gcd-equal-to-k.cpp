class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n =nums.size();
        int cnt =0;
        for(int i=0; i<n; i++)
        {
            int hcf = nums[i];
            for(int j=i; j<n; j++)
            {
                hcf = gcd(hcf, nums[j]);
                if(hcf == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};