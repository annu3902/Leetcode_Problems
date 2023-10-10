class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }

            else if(prices[i] > mini){
                int diff = prices[i] - mini;
                profit = max(profit , diff);
            }
        }
        return profit;
    }
};