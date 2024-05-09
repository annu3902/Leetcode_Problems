class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n=happiness.size();
        long long sum = 0;
        int j=0;

        for(int i=n-1; i>=n-k; i--){

            if(happiness[i] > 0){
                happiness[i]-=j;
            }

            if(happiness[i] >= 0)  
                sum+=happiness[i];

            // else break;
            j++;
        }

        return sum;
    }
};