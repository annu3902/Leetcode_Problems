class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n =coins.size();
        int cnt = 0;
        int sum = 0;
        int i = 0;
        sort(coins.begin(), coins.end());

        for(; i<n; ++i){
            if(sum < target && coins[i] <= sum+1){
                sum += coins[i];
                continue;
            }
            while(sum < target && coins[i] > sum+1){
                sum += sum+1;
                cnt++;
                if(sum >= target){
                    return cnt;
                }
            }
            sum += coins[i];
            if(sum >= target) return cnt;
        }

        if(i==n){
            while(sum < target){
                sum += sum+1;
                cnt++;
            }
        }

        return cnt;
    }
};