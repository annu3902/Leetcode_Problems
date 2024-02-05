class Solution {
private : 
    bool check(string s){
        stack <char> st;
        for(char ch : s){
            if(ch == '('){
                st.push(ch);
                continue;
            }
            else if(!st.empty()){
                st.pop();            
            }
            else{
                return false;
            }
        }
        return st.empty(); 
    }

    bool checker(string s, string locked){
        int n = s.length();
        int Fflips = 0;
        int Fopen = 0;
        int Fcloses = 0;

        for(int i = 0; i < n; i++){
            if(locked[i] == '0') Fflips++;
            else if(locked[i] == '1'){
                if(s[i] == '(') Fopen++;
                else if(s[i] == ')') Fcloses++;
                if(Fflips + Fopen < Fcloses) return false;
            }
        }
        int Rflips = 0;
        int Ropens = 0;
        int Rcloses = 0;

        for(int i = n - 1; i >= 0; i--){
            if(locked[i] == '0') Rflips++;
            else{
                if(s[i] == ')') Rcloses++;
                else if(s[i] == '(') Ropens++;
                if(Rcloses + Rflips < Ropens) return false;
            }
        }
        // return true;
        return (Fflips + Fopen >= Fcloses && Rflips + Rcloses >= Ropens);
    }

public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n & 1) return false; // if the length is odd it will never be valid

        bool result = check(s);
        if(result) return result;
        // else{
            return checker(s, locked);
        // }
    }
};