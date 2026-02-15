class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int maxLength = 2;

        //  Expanding around the centre greedy approach

        for(int i=0; i<n; i++){
            // Odd Left Skip
            int j = i-1;
            int k = i+1;
            int flag = true;

            while(j >= 0 && k < n){
                if(s[j] != s[k]){
                    if (flag) {
                        j--;
                        flag = false;
                    }else break;
                }else{
                    maxLength = max(maxLength, k - j + 1);
                    if((j > 0 || k < n-1) && flag == true){
                        maxLength = max(maxLength, k-j+2);
                    }
                    j--;
                    k++;
                }
            }

            // Odd Right Skip

            j = i-1;
            k = i+1;
            flag = true;

            while(j >= 0 && k < n){
                if(s[j] != s[k]){
                    if(flag == true){
                        k++;
                        flag = false;
                    }else break;
                }else{
                    maxLength = max(maxLength, k-j+1);
                    if((j > 0 || k < n-1) && flag == true){
                        maxLength = max(maxLength, k-j+2);
                    }
                    j--;
                    k++;
                }
            }

            // Even Left Skip

            j = i;
            k = i+1;
            flag = true;

            while(j >= 0 && k < n){
                if(s[j] != s[k]){
                    if(flag == true){
                        j--;
                        flag = false;
                    }else break;
                }else{
                    maxLength = max(maxLength, k-j+1);
                    if((j > 0 || k < n-1) && flag == true){
                        maxLength = max(maxLength, k-j+2);
                    }
                    j--;
                    k++;
                }
            }


            // Even Right skip
            j = i;
            k = i+1;
            flag = true;

            while(j >= 0 && k < n){
                if(s[j] != s[k]){
                    if(flag == true){
                        k++;
                        flag = false;
                    }else break;
                }else{
                    maxLength = max(maxLength, k-j+1);
                    if((j > 0 || k < n-1) && flag == true){
                        maxLength = max(maxLength, k-j+2);
                    }
                    j--;
                    k++;
                }
            }
        }
        return maxLength;
    }
};