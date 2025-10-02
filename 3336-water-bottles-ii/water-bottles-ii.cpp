class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int x = numBottles;
        int y = numExchange;
        int z = 0;

        int sum = 0;
        while(x){
            sum += (x);
            z += x;
            x = 0;
            while(z >= y){
                z -= y;
                x++;
                y++;
            }
            // z = (z >= y) ? (z-y) : 0; 
            // x = (z >= y) ? 1 : 0;

            // y++;
        }
        return sum;
    }
};