class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(), nums.end());

        vector<int> longestLength(n, 1);
        vector<int> prevIndex(n, -1);
        int maxLength = 1;
        int maxIndex = 0;

        // Bottom Up
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0){

                    if(longestLength[i] < 1 + longestLength[j]){
                        longestLength[i] = 1 + longestLength[j];
                        prevIndex[i] = j;
                        
                    }
                    if(maxLength < longestLength[i]){
                        maxLength = longestLength[i];
                        maxIndex = i;
                    }
                }
            }

           
        }
        vector<int> ans;

        // ans.push_back(nums[maxIndex]);
        // int currIndex = prevIndex[maxIndex];
        int currIndex = maxIndex;

        while(currIndex != -1){
            ans.push_back(nums[currIndex]);
            currIndex = prevIndex[currIndex];
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};