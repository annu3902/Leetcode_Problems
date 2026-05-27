class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> ans = nums;
        int k = right;

        while(left <= right){
            int leftElement = nums[left];
            int rightElement = nums[right];
            if(leftElement*leftElement >= rightElement*rightElement){
                ans[k]= leftElement*leftElement;
                left++;
            }
            else{
                ans[k] = rightElement*rightElement;
                right--;
            }
            k--;
        }
        return ans;
    }
};