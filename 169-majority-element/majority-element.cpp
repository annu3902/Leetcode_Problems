class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int currMax = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == currMax){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                cnt = 1;
                currMax = nums[i];
            }
        }

        int maxCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == currMax){
                maxCnt++;
            }
        }

        if(maxCnt > nums.size()/2) return currMax;
        return -1; 
    }
};