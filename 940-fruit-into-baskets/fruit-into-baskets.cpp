class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int, int> mpp;;
    
        int n = nums.size();

        int i=0;
        int j=0;
        int maxLength = 0;
        

        while(j < n){

            mpp[nums[j]]++;

            while(mpp.size() > 2){

                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);

                i++;
            }

            maxLength = max(maxLength, j-i+1);
            j++;
        }

        return maxLength;
    }
};