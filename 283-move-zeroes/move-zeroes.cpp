class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j =0; // It will start pointing to the first 0 element

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }

        for(int i =j; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};