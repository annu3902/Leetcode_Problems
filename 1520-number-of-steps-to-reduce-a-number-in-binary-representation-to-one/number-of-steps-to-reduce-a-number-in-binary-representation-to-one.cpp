class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int count = 0;
        
        while(s.size() > 1){

            int n = s.size();
            int lastIndex = n-1;

            if(s[lastIndex] == '1'){
                // No. is odd
                int i=lastIndex;
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    i--;
                }

                if(i < 0){
                    s = '1' + s;
                }
                else{
                    s[i] = '1';
                }
                count++;
            }

            else if(s[lastIndex] == '0'){
                s.pop_back();
                count++;
            }
        }
        return count;

    }
};