class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>t;
        t=nums;
        sort(t.begin(),t.end());
        bool ans;
        if(t!=nums){
        int x;
        int p=0;
        //bool ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==t[n-1]&&i!=n-1){
                if(nums[i+1]==t[0])
                x=i+1;
            }

        }
        for(int i=0;i<n;i++){
            if(t[i]==nums[(i+x)%n])
            p++;

        }
        if(p==n)
        ans=true;
        else
        ans=false;
        }
        else{
            ans=true;
        }
        return ans;
        
    }
};