class Solution {
public:
    int de2bi(int num){
        int cnt = 0;

        while(num){
            num /= 2;
            cnt++;
        }

        return cnt;
    }


    int findComplement(int num) {

        int cnt = de2bi(num);

        int number = pow(2, cnt)-1;

        return num ^ number;        
    }
};