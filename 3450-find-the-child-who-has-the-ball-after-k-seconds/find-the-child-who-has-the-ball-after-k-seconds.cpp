class Solution {
public:
    int numberOfChild(int n, int k) {
        if(k < n) return k;
        
        int number_of_rotations = k / (n-1);
        k = k % (n-1);
        
        if(number_of_rotations % 2 == 1) return n-1-k;
        else return k;
    }
};