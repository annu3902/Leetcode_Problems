class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int cntRemoval = 0;
        int n = nums.size();
        int start = -1;
        int end = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                if(cntRemoval == 0){
                    cntRemoval++;
                    start = i;
                    end = i;
                }
                else{
                    cntRemoval++;
                    end = i;
                }
            }
        }
        if(start != -1)
            nums.erase(nums.begin()+ start, nums.begin() + end + 1);
        return (n - cntRemoval);
    }
};