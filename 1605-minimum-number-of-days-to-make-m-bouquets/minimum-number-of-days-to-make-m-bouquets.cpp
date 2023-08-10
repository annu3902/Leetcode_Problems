class Solution {
public:
    bool is_possible(vector<int> bloomDay, int m, int k, long long int mid ){

        int x =m*k;
        int cnt = 0;
        int n =bloomDay.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= mid){
                // cnt++;
                bloomDay[i] = '&';
            }
            if(bloomDay[i] == '&'){
                cnt++;
                if(cnt == k){
                    sum++;
                    cnt = 0;
                }
                else{
                    continue;
                }
            }
            else{
                cnt = 0;
            }
            if(sum == m) return true;
        }
        return false;
        // for(int i =0; i<n; i++){
        //     if(bloomDay[i] == '&'){
        //         cout<<(char)bloomDay[i]<<" ";
        //     }
        // }
        // cout<<endl;

        // // cnt = 0;
        // int sum = 0;

        // for(int j =0; j<n; j++){
        //     if(bloomDay[j] == '&'){
        //         cnt++;
        //         if(cnt == k){
        //             sum++;
        //             cnt = 0;
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        //     else{
        //         cnt = 0;
        //     }
        //     if(sum == m) return true;
        // }
        // cout<<sum<<" "<<endl;
        // // if(sum >= m) return true;
        // return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        cout<<low<<" "<<high<<endl;
        if ((long long int)m * k > n) return -1;

        // if(m > n/k) return -1;
       long long int ans = -1;

        while(low <= high){
           long long int mid = low + (high - low)/2; 
            cout<<mid<<endl;
            if(is_possible(bloomDay, m, k, mid)){
                ans = mid;
                cout<<ans<<" "<<endl;
                cout<<endl;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};