class Solution {
public:

    double dfs(double x, long long y){
        if(y == 0) return 1;
        else if(y == 1) return x;

        double ans = dfs(x, y/2);
        ans = ans*ans;
        if(y % 2 != 0){
            ans = ans * x;
        }
        return ans;

    }

    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(x == 1) return 1;
        long long y = abs(static_cast<long long>(n));

        double ans = dfs(x, y);
        if(n < 0){
            return (1/ans);
        }
        return ans;
    }
};