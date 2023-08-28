class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =nums.size();
        int cnt_zero = 0;
        int left = 0;
        int right = 0;
        int max_length = 0;


        for(right = 0; right < n; right++){

            if(nums[right] == 0 && cnt_zero <= 1){
                cnt_zero++;
                while(cnt_zero > 1){
                    int length = right - left - 1;
                    max_length = max(max_length, length);
                    if(nums[left] == 0){
                        cnt_zero--;
                    }
                    left++;
                }
            }
        }
        int length = right - left - 1;
        max_length = max(max_length, length);
        return max_length;

    }
};