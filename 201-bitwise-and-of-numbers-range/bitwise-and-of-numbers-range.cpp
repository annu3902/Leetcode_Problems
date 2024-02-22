class Solution {
public:
    long long rangeBitwiseAnd(long long left, long long right) {
        if(left==0) return 0;
        if(left==right) return left;
            int leftBit;
            int rightBit;
            if(left!=0 && right!=0){
                leftBit = log2(left) +1;
                rightBit = log2(right) +1;
            }
            if(leftBit != rightBit) return 0;

            int ans = left;
            for(int k=left; k<right; k++){
                ans &= k;
            }
            ans &= right;
            return ans;
        
    }
};