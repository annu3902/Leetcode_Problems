class Solution {
public:
    string addOne(string &s){
        int n = s.size();
        int i = n-1;

        while(i >= 0 && s[i] != '0'){
            s[i] = '0';
            i--;
        }

        if(i < 0){
            s = '1' + s;
        }
        else{
            s[i] = '1';
        }
        return s;
    }

    int numSteps(string s) {
        int n =s.size();
        int ans = 0;
    
        while(s.size() > 1){
            int n =s.size();
            
            if(s[n-1] == '1'){
                addOne(s);
            }

            else{
                s.pop_back();
            }

            ans++;
        }
        return ans;
    }
};