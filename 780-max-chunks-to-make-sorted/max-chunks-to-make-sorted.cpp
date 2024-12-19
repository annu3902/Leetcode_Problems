class Solution {
public:
    int mia(int x,vector<int> ishu){
        vector<int> rita;
        for(int i=0;i<x;i++){
            rita.push_back(ishu[i]);
        }
        int max=rita[0];
        for(int i=1;i<rita.size();i++){
            if(max<rita[i]){
                max=rita[i];
            }
        }
        return max;
    }
    int jhonny(int y,vector<int> ishu1){
        vector<int> rita1;
        for(int i=y;i<ishu1.size();i++){
            rita1.push_back(ishu1[i]);
        } 
        int min=rita1[0];
        for(int i=1;i<rita1.size();i++){
            if(min>rita1[i]){
                min=rita1[i];
            }
        }
        return min;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int count=1;
        int g,h;
        for(int i=1;i<arr.size();i++){
            g=mia(i,arr);
            h=jhonny(i,arr);
            if(g<h){
                count++;
            }
        }
        return count;
    }
};