class Solution {
public:
    bool checkValidString(string s) {
        stack <char> st;
        int Fopen = 0;
        int Fclose = 0;
        int Fflip = 0;
        int n = s.size();
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') Fopen++;
            if(s[i] == ')') Fclose++;
            if(s[i] == '*') Fflip++;
            if(Fopen + Fflip < Fclose) return false;
        }

        if((Fflip & 1 == 1) && (Fopen == Fclose)) return true;

        int Ropen = 0;
        int Rclose = 0;
        int Rflip = 0;

        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(') Ropen++;
            if(s[i] == ')') Rclose++;
            if(s[i] == '*') Rflip++;
            if(Rclose + Rflip < Ropen) return false;
        }

        if((Rflip & 1 == 1) && (Ropen == Rclose)) return true;

        return (Fopen + Fflip >= Fclose && Rclose + Rflip >= Ropen);
    }
};