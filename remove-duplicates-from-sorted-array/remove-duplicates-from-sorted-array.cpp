class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0; j<nums.size(); j++)
        {
            // int j =i+1;
            if(nums[j]!=nums[i])
            {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};