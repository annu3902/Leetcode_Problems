class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int left = 0;
        int right = 0;
        int max_length = 0;
        
        while(right < n){

            if(nums[right] == 0){
                if(k>0){
                    k--;
                    right++;
                }

                else{
                    int length = right - left;
                    max_length = max(length, max_length);
                    while(left <= right &&  k==0){
                        if(nums[left] == 0){
                            k++;
                        }
                        left++;
                    }
                }

            }
            else if(nums[right] == 1){
                right++;
            }
        }
        max_length = max(right-left, max_length);
        return max_length;

    }
};