class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int i=0;
        int j=0;
        int maxLength = 0;
        int costOfConversion = 0;

        while(j < s.size()){

            costOfConversion += abs(s[j] - t[j]);

            if(costOfConversion <= maxCost){
                int length = j-i+1;
                maxLength = max(maxLength, length);
            }

            while(costOfConversion > maxCost){ // bringing back the costOfConversion on the limit i.e maxCost
                costOfConversion -= abs(s[i] - t[i]);
                i++;
            }

            j++;
        }
        return maxLength;

    }
};