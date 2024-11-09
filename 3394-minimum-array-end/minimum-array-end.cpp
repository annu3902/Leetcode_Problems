class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long steps = n-1;
        int idx = 0;
        while(steps){
            if( !(x & (1LL << idx) ) ){
                ans |= (steps&1LL) << idx;
                steps /=2;
            }
            idx++;
        }

        return ans;
    }
};