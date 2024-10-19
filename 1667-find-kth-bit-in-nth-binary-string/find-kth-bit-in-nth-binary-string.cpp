class Solution {
public:
    string invertfunction(string str){
        string s = "";
        for(int i=0 ; i<str.size(); i++){
            if(str[i] == '0'){
                s+="1";
            }else{
                s+="0";
            }
        }
        return s;
    }

    string solve(int n , int k){
        string str = "0";
        for(int i=1 ; i<=n ; i++){
            string str1 = str + "1";
            string str2 = invertfunction(str);
            reverse(str2.begin() , str2.end());
            str = str1 + str2;
        }
        return str;
    }

    char findKthBit(int n, int k) {
        string str = solve(n , k);
        char ch = str[k-1];
        return ch;
    }
};