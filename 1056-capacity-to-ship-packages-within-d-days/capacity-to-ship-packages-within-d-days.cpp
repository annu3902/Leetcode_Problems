class Solution {
public:

    bool is_possible(vector<int> weights, int days, long long mid){
        int n = weights.size();
        int day_count = 1;
        int weight_count = 0;

        for(int i=0; i<n; i++)
        {
            if(weight_count + weights[i] <= mid){
                weight_count += weights[i];
            }else{
                day_count++;
                if(day_count > days || weights[i] > mid){
                    return false;
                }
                weight_count = weights[i];
            }
        }
        if(day_count <= days){
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 1;
        int high = accumulate(weights.begin(), weights.end(),0);

        while(low <= high){
            long long int mid = (low + high)/2;

            if(is_possible(weights,days, mid)){
                // ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};