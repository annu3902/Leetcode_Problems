class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        long long int max_sum = 0;
        unordered_map<int,int> mpp;
        long long int sum = 0;
        int i =0;
        int j =0;

        while(j < n)
        {
            sum = sum + nums[j];
            mpp[nums[j]]++;

            if(j-i+1 == k && mpp.size() < k){
                if(mpp.find(nums[i]) != mpp.end()){
                    sum = sum - nums[i];
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0){
                        mpp.erase(nums[i]);
                    }
                    i++;
                }
                // j++;
            }

            else if(j-i+1 == k && mpp.size() == k){

                max_sum = max(max_sum, sum);

                if(mpp.find(nums[i]) != mpp.end()){
                    sum = sum - nums[i];
                    // mpp.erase(nums[i]);
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0){
                        mpp.erase(nums[i]);
                    }
                    i++;
                }
            }

            j++;
        }

        return max_sum;


        // for(int i =0; i<=n-k; i++){


        //     for(int j =i; j<i+k; j++){
        //         mpp[nums[j]]++;
        //         sum += nums[j];
        //     }

        //     int cnt = 0;

        //     for(auto it : mpp){
        //         if(it.second == 1){
        //             cnt++;
        //         }
        //     }   

        //     if(cnt == k){
        //         max_sum = max(max_sum, sum);
        //     }

        //     // cnt = 0;
        //     // mpp.clear();
        // }
        // return max_sum;   

        // int n = nums.size();
        // deque<int>dp;
        // int sum = 0;
        // int max_sum = INT_MIN;
        // int x = k;
        // int idx = -1;
        // for(int i=0;i<n;i++){
        //     if(x>0){
        //         if(dq.size()==0){
        //             dq.push_back(nums[i]);
        //             sum+=nums[i];
        //             x--;
        //         }
        //         else{
        //             int ft = dq.front();
        //             int ed = dq.end(); 
        //             if(nums[i]!=ft && nums[i]!=ed){
        //                 dq.push_back(nums[i]);
        //                 sum+=nums[i];
        //                 x--;
        //             }
        //             else{
        //                 sum = 0;
        //                 x = k;
        //                 dq.clear();
        //             }
        //         }
        //     }
        //     else{
        //         idx = i;
        //         break;
        //     }
        // }

        // max_sum=max(max_sum,sum);

        // for(int i=idx;i<n;i++){

        // }
    }
};