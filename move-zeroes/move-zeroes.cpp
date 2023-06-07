class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int count =0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]!=0){
        //         count++;
        //         break;
        //     }
        // }
        // if(count==0)
        // {
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         cout<<nums[i];
        //     }
        // }
        
        // int j= 0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]!=0)
        //     {
        //         nums[j]=nums[i];
        //         j++;
        //     }
        // }
        // for(int i=j; i<nums.size(); i++)
        // {
        //     nums[i]=0;
        // }
        // for(int i=0;i<nums.size();i++)
        // {
        //    cout<<nums[i];
        // }
        int j =0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        for(int i =j; i<nums.size(); i++)
        {
            nums[i] = 0;
        }

        // for(int i=0;i<nums.size();i++)
        // {
        //    cout<<nums[i];
        // }
    }
};