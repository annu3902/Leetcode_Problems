class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxArea = 0;
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start < end){
            if(nums[start] <= nums[end]){
                int y = nums[start];
                int x = end - start;

                int area = x*y;
                maxArea = max(maxArea, area);
                start++;
            }
            else{
                int y = nums[end];
                int x = end - start;

                int area = x*y;
                maxArea = max(maxArea, area);
                end--;
            }
        }

        return maxArea;
    }
};