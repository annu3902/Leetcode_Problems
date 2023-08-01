class Solution {
public:
    int mySqrt(int x) {
        int temp =x;
        long long int i;
        for(i=0; i*i<=temp; i++)
        {
            if(i*i == temp){
                return i;
            }
        }
        return i-1;
    }
};