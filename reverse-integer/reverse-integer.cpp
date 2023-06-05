class Solution {
public:
    int reverse(int x) {
        int temp =x;
        long long int sum =0;
        while(temp!=0){
            int y = temp%10;
            sum =sum*10+y;
            temp = temp/10;
        }

        if(sum <INT_MIN || sum>INT_MAX)
        {
            return 0;
        }
        else{
            return sum;
        }
    }
};