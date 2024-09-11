class Solution {
public:
    string de2bi(int number){
        string result="";

        while(number){
            int lastDigit = number % 2;
            result.push_back(lastDigit + '0');
            number /= 2;
        }

        int size = result.size();
        string temp = "";
        for(int i=0; i<32-size; i++){
            temp += '0';
        }

        reverse(begin(result), end(result));
        temp += result;
        return temp;

    }

    int minBitFlips(int start, int goal) {
        string st = de2bi(start);
        string end = de2bi(goal);

        cout<<st<<" "<<end;

        int cnt = 0;
        for(int i=0; i<32; i++){
            if(st[i] != end[i]){
                cnt++;
            }
        }

        return cnt;
    }
};