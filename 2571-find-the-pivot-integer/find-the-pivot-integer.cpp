class Solution {
public:
    int pivotInteger(int n) {
        int num = ((n*n)+n)/2;
        double val1 = sqrt(num);
        int val2 = sqrt(num);
        int ans = (val1==val2) ? val2 : -1;
        return ans;
    }
};