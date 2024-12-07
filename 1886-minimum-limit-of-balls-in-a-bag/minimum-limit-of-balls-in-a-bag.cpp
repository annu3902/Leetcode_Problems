class Solution {
public:
    bool isPoss(int mid, vector<int>&nums,int maxOperations)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
            cnt+=((nums[i]-1)/mid);
        }

        return cnt<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1,r=0;
        for(int i=0;i<n;i++)
        r=max(r,nums[i]);

        int ans=1e9;

        while(l<=r)
        {
            int mid=(l+r)/2;

            if(isPoss(mid,nums,maxOperations))
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;


    }
};