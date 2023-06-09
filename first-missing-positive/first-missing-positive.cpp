class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for(int j =1; j<=nums.size(); j++)
        {
            if(mpp[j] == 0) 
            {   return j;
               break;
            }   
        }
        return nums.size()+1;
    }
};