class Solution {
public:
    int numWaterBottles(int Bottles, int Exchanges) {
        int ans = Bottles;
        int empty = Bottles;
        while(empty >= Exchanges){
            Bottles = empty/Exchanges;
            ans += Bottles;
            empty %= Exchanges;
            empty += Bottles;
        }
        return ans;
    }
};