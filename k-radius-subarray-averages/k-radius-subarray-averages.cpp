class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n =nums.size();
        int K = 2*k+1;
        vector<int> ans(n,-1);
        long long int sum =0;

        if(k ==0){
            return nums;
        }

        if(K > n){
            return ans;
        }

        while(j < n){

            sum += nums[j];
            // if()
            if(j-i+1 < K){
                j++;
            }

            else if(j-i+1 ==K){
                long long int avg = sum/K;
                int x =(i+j)/2;
                ans[x] = avg;

                sum -= nums[i];
                i++; j++;

            }
        }
        return ans;
    }
};