class Solution {
public:

    int slidingWindow(vector<int>& nums, int mid){

        int n = nums.size();
        int i = 0;
        int j = i+1;
        int countPairs = 0;

        while(j < n){

            while(i<n && abs(nums[j] - nums[i]) > mid){
                i++;
            }
            
            countPairs += (j-i);
            j++;
        }
        return countPairs;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int lowDist = 0;
        int highDist = nums[n-1] - nums[0];

        int ans = 0;

        while(lowDist <= highDist){

            int mid = lowDist + (highDist - lowDist)/2;

            int pairCount = slidingWindow(nums, mid);

            if(pairCount < k){
                lowDist = mid + 1;
            }
            else{
                ans = mid; // mid stores that kth - distance
                highDist = mid-1;
            }

        }

        return ans;
    }
};