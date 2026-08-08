class Solution {
public:
    bool canHandleWeight(vector<int>& weights, int maxWeight, int days){
        int n = weights.size();

        int dayCount = 1;
        int shipWeight = 0;

        for(int i=0; i<n; i++){
            if(shipWeight + weights[i] <= maxWeight){
                shipWeight += weights[i];
            }
            else{
                dayCount++;
                shipWeight = weights[i];
            }
            if(dayCount > days) return false;
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int left = *max_element(begin(weights), end(weights));
        int right = accumulate(begin(weights), end(weights), 0);

        while(left < right){
            int mid = left + (right - left)/2;

            if(canHandleWeight(weights, mid, days)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};