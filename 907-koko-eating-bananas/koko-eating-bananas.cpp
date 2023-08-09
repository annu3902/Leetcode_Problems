class Solution {
public:
    bool is_possible(vector<int>& piles, long long int h, long long int mid){
        int n =piles.size();
        long long int sum = 0;
        
        for(int i=0; i < n; i++)
        {
            long long int cnt = ceil ((double)piles[i]/ (double)mid);
            sum += cnt;
        }
        cout<<sum<<" ";
        if(sum <= h){
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, long long int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(),piles.end());
        
        int low = 1; 
        int high = maxi;
        int ans = INT_MAX;

        while(low <= high){
           long long int mid = (low + high )/2;

            if(is_possible(piles, h, mid)){
                ans = mid;
                // cout<<ans<<" ";
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};