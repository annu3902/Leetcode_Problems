class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        vector<string> distinct;
        for(int i = 0;i < arr.size();i++){
            mpp[arr[i]]++;
        }

        for(auto it : arr){
            if(mpp[it] == 1){
                distinct.push_back(it);
            }
        }
        if(k <= distinct.size()){
            return distinct[k - 1];
        }
        else{
            return "";
        }
    }
};