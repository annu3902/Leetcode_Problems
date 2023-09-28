class Solution {
public:
    string categorizeBox(long long int length, long long int width, long long int height, int mass) {
        long long volume = (long long) (length*width*height);
        bool flag1 = false;
        bool flag2 = false;

        if(length >= pow(10,4) || width >= pow(10,4)|| height >= pow(10,4) || volume >= pow(10,9)){
            flag1 = true;
        }

        if(mass >= 100 ){
            flag2 = true;
        }

        if(flag1 && flag2) return "Both";
        else if(flag1 == 1 && flag2 == 0) return "Bulky";
        else if(flag1 == 0 && flag2 == 1) return "Heavy";
        else return "Neither";
    }
};