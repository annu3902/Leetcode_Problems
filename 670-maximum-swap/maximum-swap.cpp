class Solution {
public:
    int maximumSwap(int num) {
        
        string str = to_string(num);
        int n = str.size();

        for(int i=0;i<n;i++){

            int max_val = -1;
            int idx = i;
            
            for(int j=i;j<n;j++){

                  if( max_val <= str[j]-'0'){
                        max_val = str[j] - '0';
                        idx = j;
                        
                  }
            }

            if(idx!=i and str[i]!= str[idx]){

                swap(str[i],str[idx]);
                return stoi(str);

            }

        }
        
        return num;

    }
};