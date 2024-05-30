class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();

        int i = 0;
        int j = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while(j < n){

            if(nums[j] == 0) zeroCount++;

            while(zeroCount > k){

                if(nums[i] == 0) zeroCount--;
                i++;

            }

            int length = j-i+1;
            maxLength = max(maxLength, length);

            j++;
        }

        maxLength = max(maxLength, j-i);
        return maxLength;
    }
};