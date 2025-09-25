class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int left = 0; 
       int right = 1;

       for(; right < nums.size(); right++){
            if(nums[right] != nums[left]){
                nums[left + 1] = nums[right];
                left++;
            }
       } 

       return left+1;
    }
};