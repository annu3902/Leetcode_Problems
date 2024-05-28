class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();

        int count1 = slidingWindow(nums, k);

        int count2 = slidingWindow(nums, k-1);
    
        return (count1-count2);
    }

    int slidingWindow(vector<int> &nums, int k){

        int n = nums.size();

        int i=0;
        int j=0;
        unordered_map<int, int> mpp;
        int countSubarrays = 0;

        while(j < n){

            mpp[nums[j]]++;

            while(mpp.size() > k){

                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }

                i++;
            }

            if(mpp.size() <= k){
                countSubarrays += (j-i+1); // counting the subarays having the unique elements less than or equals to k
            }

            j++;

        }

        return countSubarrays;
    }

};