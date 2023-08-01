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

        if(x == 0 || x == 1){
            return x;
        }

        else{
            int low = 2;
            int high = INT_MAX;
            long long int mid = -1;

            while(low <= high){
                mid = low + (high-low)/2;

                if(mid*mid < x){
                    low = mid+1;
                }
                else if(mid*mid == x){
                    return mid;
                }

                else{
                    high = mid-1;
                }
            }
            return high;
        }
    }
};