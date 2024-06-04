class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // dp[i] -> pair of length of longest increasing subsequence with its count

        int n = nums.size();

        vector<pair<int, int>> dp(n);

        for(int i=0; i<n; i++){
           dp[i] = {1,1};
        }

        // int maxCnt = 0;
        // int maxLength = 0;

        for(int i=0; i<n; i++){

            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == 1 + dp[j].first){
                        dp[i].second += dp[j].second;
                        // maxCnt = max(max)
                    }
                    else if(dp[i].first < 1 + dp[j].first){
                        dp[i].second = dp[j].second;
                        dp[i].first = 1 + dp[j].first;
                    }
                }
            }

            // if(dp[i].first == maxLength){
            //     maxCnt += dp[i].second;
            // }

            // else if(maxLength < dp[i].first){
            //     maxLength = dp[i].first;
            //     maxCnt = dp[i].second;
            // }
        }

        int maxLength =0;
        int ans =0;
        for(auto & it : dp){

            int length = it.first;
            int freq = it.second;

            if(length > maxLength){
                maxLength = length;
                ans = freq;
            }
            else if(length == maxLength){
                ans += freq;
            }

        }

        return ans;



        // return maxCnt;

        // int cnt= 0;

        // for(pair<int, int> it : dp){
        //     int length = it.first;
        //     int freq = it.second;
        //     // cout<<length<<" "<<freq<<" "<<endl;

        //     if(maxLength < length){
        //         maxLength = length;
        //         cnt = freq;
        //         // cout<<cnt<<" "<<1<<endl;
        //         maxCnt = max(cnt, maxCnt);
        //     }

        //     else if(maxLength == length){
        //         cnt += freq;
        //         // cout<<cnt<<" "<<2<<endl;
        //         maxCnt = max(cnt, maxCnt);
        //     }

        //     else{
        //         continue;
        //     }

        // }

        // return maxCnt;
    }
};