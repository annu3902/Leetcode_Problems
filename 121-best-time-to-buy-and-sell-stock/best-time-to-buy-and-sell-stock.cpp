// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini = prices[0];
//         int profit =0;
//         for(int i=1; i<prices.size(); i++)
//         {
//             mini = min(mini, prices[i-1]);
//             profit = max(profit, prices[i] - mini);
//         }
//         return profit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // int maxi = 0;
        // for(int i =0; i<n; i++)
        // {
        //     for(int j=i+1; j<n; j++){
        //         if(prices[j] > prices[i]){
        //             int diff = prices[j] - prices[i];
        //             maxi = max(maxi, diff);
        //         }
        //     }
        // }
        // return maxi;

        // int n =prices.size();
        // int maxi =0;
        // int mini = prices[0];
        // for(int i=1; i<n; i++)
        // {
        //     mini = min(mini, prices[i]);
        //     int diff = prices[i] - mini;
        //     maxi = max(maxi, diff);
        // }
        // return maxi;

        int n =prices.size();
        int left = 0;
        int max_profit = 0;

        for(int right = 1; right<n; right++){
            if(prices[right] < prices[left]){
                left = right;
            }

            int diff = prices[right] - prices[left];
            max_profit = max(max_profit, diff);
        }
        return max_profit;
    }
};