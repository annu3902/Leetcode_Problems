class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0 && nums[i] <=n)
                mpp[nums[i]]++;
        }

        for(int j =1; j<=n; j++)
        {
            if(mpp[j] == 0) 
            {   return j;
               break;
            }   
        }
        return n+1;
    }
};