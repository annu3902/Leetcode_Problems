class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;

        int n = prices.size();
        int maxi = 0;
        int mini = prices[0];

        for(int i=1; i<n; i++){
            int diff = prices[i] - mini;

            mini = min(mini, prices[i]);
            maxi = max(maxi, diff);
            // if(prices[i] < mini){
            //     mini = prices[i];

            // }
        }
        return maxi;
    }
};