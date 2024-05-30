class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int minLength = INT_MAX;
        int sum = 0;
        int maxIndex = 0;

        int maxElement = *max_element(nums.begin(), nums.end());
        if(target < maxElement) return 1;

        map<int, int> mpp;

        for(int i=0; i<n; i++){

            sum += nums[i];

            if(sum == target){
                int length = i+1;
                minLength = min(minLength, length);
            }

            else if(mpp.count(sum - target)){
                int length = i - mpp[sum - target];
                minLength = min(minLength, length);
            }

            else if(sum > target){

                int diff = sum - target;
                
                for(auto it : mpp){
                    if(it.first< diff){
                        maxIndex = it.second;
                    }
                    else{
                        break;
                    }
                }// 2 5 6 8

                if(maxIndex != 0) minLength = min(minLength, i - maxIndex);
                else
                    minLength = min(minLength, i - maxIndex+1);
            }
            mpp[sum] = i;
        }

        return minLength == INT_MAX ? 0 : minLength;

    }
};
