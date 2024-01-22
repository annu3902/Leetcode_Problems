class Solution {
public:
    double helper(double x, int n){
        // Base Case
        if(n == 0) return 1;
        // Processing 
        double partialAns = helper(x, n / 2);
        partialAns *= partialAns;

        if(n % 2 != 0) return (x * partialAns);
        return partialAns;
    }

    double myPow(double x, int n) {
        int y = abs(n);
        double partialAns = helper(x , y);
        if(n < 0) return (1 / partialAns);
        return partialAns;
    }
};



