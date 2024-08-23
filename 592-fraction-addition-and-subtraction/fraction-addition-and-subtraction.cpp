// class Solution {
// public:
//     string fractionAddition(string s) {
        // Edge Cases
        // 1. If numerator is 0
        // 2. If numerator is an integer -> Print denominator to be 1
        // 3. If denominator is the factor of numerator or vice-versa
        // 4.
        // int n = s.length();
        // vector<int> denominator;
        // vector<int> numerator;

        // for(int i=1; i<n; i++)
        // {
        //     if(s[i-1] == '/'){
        //         denominator.push_back(s[i]);
        //     }
        //     else if(s[i-1] >= '1' && s[i-1] <= '9' && s[i] == '/'){
        //         numerator.push_back(s[i-1]);
        //     }
        // }

        // for(int i : numerator){
        //     cout<<i<<" ";
        // }
        // return s;


        #include<bits/stdc++.h>
class Solution {
public:
    string fractionAddition(string s) {
       int num=0,den = 1;

       int n= s.size();
       int i=0;

       while(i<n){

        int curr_num=0,curr_den=0;

        bool isNegative = false;

        if(s[i]=='-'){
            isNegative = true;
            i++;
        }
        else if(s[i]=='+'){i++;}
        
        while(i<n and (s[i]>='0' and s[i]<='9')){
            curr_num = (curr_num*10) + (s[i]-'0');
            i++;
        }
        
        if(isNegative){
            curr_num *=-1;
        }

        if(s[i]=='/'){i++;}

        
        while(i<n and (s[i]>='0' and s[i]<='9')){
            curr_den = (curr_den *10)+(s[i]-'0');
            i++;
        }
        
    
        num = (num*curr_den) +(den * curr_num);
        den = (den * curr_den);
    } 

       int gcd_val = __gcd(abs(num),den);

       num/=gcd_val;
       den/=gcd_val;

      string ans = to_string(num)+"/"+to_string(den);

       return ans;
    }
};
//     }
// };