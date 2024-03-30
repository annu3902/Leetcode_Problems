class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n=possible.size();
        vector<int> prefixSum;
        int sum =0;
        for(int i=0; i<n; i++){
            sum += (possible[i] == 1) ? 1 : -1;
            prefixSum.push_back(sum);
        }
        for(int i=0; i<n-1; i++){
            if(2*prefixSum[i]>prefixSum[n-1]) return i+1;
        }
        return -1;
    }
};