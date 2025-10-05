class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }

        for(int j=n-1; j>index; j--){
            if(index != -1 && nums[j] > nums[index]){
                swap(nums[index], nums[j]);
                break;
            }
        }

        reverse(nums.begin()+index+1, nums.end());

    }
};