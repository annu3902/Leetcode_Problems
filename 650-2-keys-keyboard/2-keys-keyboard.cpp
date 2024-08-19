class Solution {
public:
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }

        int countChar = 1;
        int steps = 0;
        int temp = 0;
        while(countChar < n){
            if(n % countChar == 0){
                steps++; // copy
                temp = countChar;
            }
            steps++; // paste
            countChar = countChar + temp;
        }

        return steps;
    }
};