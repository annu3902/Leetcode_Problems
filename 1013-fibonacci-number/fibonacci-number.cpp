class Solution {
public:
    int fib(int n) {
        int dp0 = 0;
        int dp1 = 1;
        int finalAns=0;
        if(n==0) return dp0;
        if(n==1) return dp1;
        
        for(int i=2; i<=n; ++i){
            finalAns=dp0+dp1;
            dp0=dp1;
            dp1=finalAns;
        }
        return finalAns;
    }
};