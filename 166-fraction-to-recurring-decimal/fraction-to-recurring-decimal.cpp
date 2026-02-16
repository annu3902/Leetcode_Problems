class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0) return "0";

        string ans = "";
        if((num < 0) ^ (den < 0)) ans += "-";

        long n = labs((long)num);
        long d = labs((long)den);

        ans += to_string(n/d);
        long r = n % d;
        if(r == 0) return ans;

        else{
            ans += '.';
            unordered_map<int, int> mp;
            while(r != 0){
                if(mp.count(r)){
                    ans.insert(mp[r], "(");
                    ans += ')';
                    break;
                }
                mp[r] = ans.size();
                r *= 10;
                ans += to_string(r/d);
                r %= d;
            }
        }
        return ans;
        
    }
};