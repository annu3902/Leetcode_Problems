class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count = 0;
        int sum = 0;
        int flag = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') {
                flag = 1;
                count++;
            }
            else{
                if(flag == 1)sum += count;
                flag = 0;
            }
        }
        return sum;
    }
};