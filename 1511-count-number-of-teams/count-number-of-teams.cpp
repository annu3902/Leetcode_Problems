class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n= rating.size();
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(rating[i]<rating[j]){
                    for(int k=j+1; k<n;k++){
                        if(rating[j]<rating[k]){
                            ans++;
                        }
                    }
                }     
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(rating[i]>rating[j]){
                    for(int k=j+1; k<n;k++){
                        if(rating[j]>rating[k]){
                            ans++;
                        }
                    }
                }     
            }
        }

        return ans;
    }
};