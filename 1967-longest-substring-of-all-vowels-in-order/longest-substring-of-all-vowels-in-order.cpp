class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.size();
        // vovel appers in alphabatical orders atleast once for maximum length
        if(n<5) return 0;
        int need ='a';
        int last = 'a';
        int length = 0;
        int maxLen = 0;
        int flag = 0;

        for(int i=0; i<n; ++i){
            char ch = word[i];
            if(need == 'a' && ch=='a'){
                length++;
                need = 'e';
            }

            else if(need=='e' && (ch=='a'||ch=='e')){
                length++;
                if(ch=='e'){
                    need='i';
                } 
            }

            else if(need=='i' && (ch=='e'||ch=='i')){
                length++;
                if(ch=='i'){
                    need='o';
                } 
            }

            else if(need=='o' && (ch=='i'||ch=='o')){
                length++;
                if(ch=='o'){
                    need='u';
                } 
            }

            else if(need=='u' && ch =='o' && flag==0){
                length++;
            }

            else if(need=='u' && ch=='u'){
                // else if(ch=='u'){
                    flag=1;
                    length++;
                    maxLen = max(maxLen , length);
                // }
                 
            }
            else {
                flag=0;
               if(ch=='a'){
                   length=1;
                   need='e';
               }
               else need='a', length=0;
            }
        }

        // if(word.back()=='u'){
        //     maxLen = max(maxLen , length);
        // } 
        return maxLen;
    }
};