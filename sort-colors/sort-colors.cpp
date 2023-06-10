class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hashh [3] = {0};

        for(int i=0; i<nums.size(); i++)
        {
            hashh[nums[i]]++;
        }

        int i=0;
        while(hashh[0] -- && i<nums.size()){
            nums[i] = 0;
            i++;
        }

        while(hashh[1] -- && i<nums.size()){
            nums[i] = 1;
            i++;
        }

        while(hashh[2] -- && i<nums.size()){
            nums[i] = 2;
            i++;
        }
    }
};