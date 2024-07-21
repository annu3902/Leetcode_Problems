class Solution {
public:
    int minChanges(int n, int k) {
        if((n & k )!= k) return -1;
        
        else if(n == k) return 0;

        int diffBits = n^k;

        int count = 0;

        for(int i=0; i<32; i++){
            if((diffBits & (1<<i))){
                count++;
            }
        }
        return count;
    }
};