class Solution {
public:
const long long mod = 1e9+7;

   long long int power(int number, long long int exponent){
        // Base Case
        if(exponent == 0) return 1;
        if(exponent == 1) return number % mod;

        // Processing
        long long int ans = power(number, exponent / 2) % mod;
        ans = (ans * ans) % mod;     
        if(exponent & 1){
            ans = (ans * number) % mod;
        } 
        return ans % mod;
    }


    int countGoodNumbers(long long n) {
    long long int oddPosition = n / 2;
    long long int evenPosition = n - oddPosition;

    long long int evenAns = power(5, evenPosition);
    long long int oddAns = power(4, oddPosition);

    long long ans = (evenAns * oddAns) % mod;

    return static_cast<int>(ans);
}

};

