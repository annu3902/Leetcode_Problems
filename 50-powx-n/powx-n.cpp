class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        int temp = n;
        n = abs(n);

        double partialans = myPow(x, n/2);
        double result = (temp >= 0) ? (partialans * partialans) : (1/partialans * 1/partialans);

        if(n % 2 == 1) {
            // double check = (result >= 1 ) ? (result*x) : (1/x * result);
            if(temp < 0){
                return (1/x * result);
            }else{
                return (x * result);
            }
            // return check;
        }

        return result;
    }
};