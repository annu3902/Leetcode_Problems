class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <=0) return false;

        if((n & (n-1)) == 0) return true;
        return false;
    }
};

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0) {
//             return false;
//         }
        
//         return (n & (n - 1)) == 0;
//     }
// };