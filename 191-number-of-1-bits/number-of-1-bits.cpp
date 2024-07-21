class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for(int pos=0; pos<32; pos++){
            if((n & (1<<pos)) != 0) count++;
        }
        return count;
    }
};