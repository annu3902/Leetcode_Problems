class Solution {
public:
    int mySqrt(int x) {
        // int temp =x;
        // long long int i;
        // for(i=0; i*i<=temp; i++)
        // {
        //     if(i*i == temp){
        //         return i;
        //     }
        // }
        // return i-1;

        
            double low = 1;
            double high = x;
            long long int mid = -1;
            if(x == 0) return 0;
            double ans = INT_MIN;
            while(low <= high){
                mid = low + (high-low)/2;

                if(mid*mid <= x){
                    ans = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            cout<<ans<<endl;
            return ans;
    }
};