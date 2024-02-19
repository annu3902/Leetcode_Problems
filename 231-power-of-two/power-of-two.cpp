class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        double x = log2(n);
        int y = log2(n);
        if(x == y) return true;
        return false;
    }
};