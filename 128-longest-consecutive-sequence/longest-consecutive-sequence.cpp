class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        if(nums.empty()) return 0;

        int length = 1;
        int maxLength = 1;
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] == (nums[i-1] + 1)){
                length += 1;
                maxLength = max(length, maxLength);
            }else if((nums[i] ^ nums[i-1]) == 0){
                continue;
            }else{
                length = 1;
            }
        }

        return maxLength;
    }
};