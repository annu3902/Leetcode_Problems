class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m/2;

        int totalSum = accumulate(begin(nums), end(nums), 0);

        vector<int> left(nums.begin(), nums.begin()+n);
        vector<int> right(nums.begin()+n, nums.end());

        unordered_map<int, vector<int>> rightMap;
        unordered_map<int, vector<int>> leftMap;

        for(int mask=0; mask<(1<<n); mask++){
            int sumL=0; int cnt=0;
            int sumR=0;

            for(int j=0; j<n; j++){
                if((mask & (1<<j))){
                    sumL = sumL + left[j];
                    sumR = sumR + right[j];
                    cnt++;
                }
            }

            leftMap[cnt].push_back(sumL);
            rightMap[cnt].push_back(sumR);
        }

        for(auto& it : rightMap){
            sort(begin(it.second), end(it.second));
        }

        int ans = INT_MAX;

        for(auto it : leftMap){
            int k = it.first; //getting k elements from lefthalf
            vector<int> leftVec = it.second;
            vector<int>& rightVec = rightMap[n-k];

            for(auto& currSum : leftVec){
                int need = totalSum/2 - currSum;

                auto lb = lower_bound(rightVec.begin(), rightVec.end(), need);

                if(lb != rightVec.end()){
                    int sum2 = *lb;
                    int sum1 = currSum;
                    int total = sum1 + sum2;
                    ans = min(ans, abs(totalSum - 2 * (total)));
                }

                if(lb != rightVec.begin()){
                    lb--;
                    int sum2 = *lb;
                    int sum1 = currSum;
                    int total = sum1 + sum2;
                    ans = min(ans, abs(totalSum - 2*(total)));
                }
            }
        } 
        return ans;   
    }
};