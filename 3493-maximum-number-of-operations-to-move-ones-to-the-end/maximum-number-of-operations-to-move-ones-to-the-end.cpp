class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count = 0;
        int sum = 0;

        for(int i=1; i<n; i++){
            if(s[i-1] == '1') count++;
            
            else if(s[i] == '0' && s[i-1] == '0') continue;

            else{
                sum += count;
            }
        }
        if(s.back() == '0') sum += count;

        return sum;
    }
};