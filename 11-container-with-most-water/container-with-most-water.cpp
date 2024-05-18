class Solution {
public:
    int maxArea(vector<int>& nums) {
        int weidth = nums.size() - 1;

        int i = 0;
        int j = weidth;

        int maxxArea = 0;

        while(i<j){

            int height = min(nums[i], nums[j]);
            int area = height*weidth;

            maxxArea = max(maxxArea, area);

            if(nums[i] < nums[j]){
                i++;
            }
            else{
                j--;
            }
            weidth--;
        }

        return maxxArea;

    }
};