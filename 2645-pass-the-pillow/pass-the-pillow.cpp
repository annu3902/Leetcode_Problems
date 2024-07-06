class Solution {
public:
    int passThePillow(int n, int time) {
        if(time < n) return (time + 1);

        int round = time / (n-1);
        if(round & 1) return (n- (time % (n-1)));
        return (time % (n-1)) + 1;
    }
};