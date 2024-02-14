class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n =nums.size();

        if(n==1) return 1;
        if(n==2){
            if(nums[1] != nums[0]) return 2;
            else return 1;
        }

        int prevDiff = nums[1]-nums[0];
        int currDiff;
        int count;
        if(nums[0] != nums[1]) count = 2;
        else count =1;

        for(int i=2; i<n; ++i){
            currDiff = nums[i]-nums[i-1];
            // long long product = prevDiff*currDiff;
            // if(product < 0){
            //     count++;
            //     prevDiff = currDiff;
            // }
            if((prevDiff >= 0 && currDiff < 0) || (prevDiff <= 0 && currDiff > 0)){
                count++;
                prevDiff = currDiff;
            }
        }
        return count;
    }
};