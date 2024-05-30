class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        // Creating a prefixXorr for the elements for fast accessing

        vector<int> prefixXor(arr.begin(), arr.end());
        prefixXor.insert(prefixXor.begin(), 0);


        int n = prefixXor.size();
        for(int i=1; i<n; i++){
            prefixXor[i] ^= prefixXor[i-1]; 
        }

        int count=0;
        for(int i=0; i<n; i++){

            for(int k=i+1; k<n; k++){
                if(prefixXor[i] == prefixXor[k]) count += (k-i-1);
            }

        }
        return count;
    }
};