class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int sum = 1;
        int maxi = 0;
        if(n == 1) return 1;

        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                sum++;    
            }
            else{
                maxi = max(sum, maxi);
                sum = 1;
            }
        }

        if(sum > maxi){
            return sum;
        }

        return maxi;
    }
};