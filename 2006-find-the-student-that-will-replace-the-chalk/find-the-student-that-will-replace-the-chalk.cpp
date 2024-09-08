class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ans = -1;
        int n = chalk.size();

        vector<long long> prefixSum;
        for(auto it : chalk){
            prefixSum.push_back(it);
        }
        // prefixSum[0] = chalk[0];
        for(int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1];
        }

        // Using Binary Search to find when the chalk will over
        k %= prefixSum[n-1];
        int low = 0;
        int high = n-1;
        // cout<<k<<" ";

        while(low <= high){
            int mid = low + (high - low)/2;

            if(prefixSum[mid] < k){
                low = mid + 1;
            }

            else if(prefixSum[mid] > k){
                high = mid - 1;
            }

            else{
                return (mid + 1) % n;
            }
        }
        return low;
    }
};