class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
            int i =0;
            int j =0;
            int min_len = INT_MAX;
            int sum = 0;
            int n =nums.size();

            while(i<n){

                sum = sum +nums[i];

                while(j<=i && sum >= target){
                    min_len = min(min_len, i-j+1);
                    sum = sum -nums[j];
                    j++;
                }

                i++;
        
            }
        return min_len == INT_MAX ? 0 : min_len;
    }
};  

