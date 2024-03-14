class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefixSum;
        int n=nums.size();
        int sum=0;
        for(int x : nums){
            sum+=x;
            prefixSum.push_back(sum);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(prefixSum[i] == goal) cnt++; 
            for(int j=i+1; j<n; j++){
                if(prefixSum[j]-prefixSum[i] == goal){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};