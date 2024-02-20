class Solution {
public:

    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        unordered_map<int, int> mpp; // map will store the element with its current index

        for(int i=0; i<n; ++i)
            mpp[row[i]] = i;

        for(auto it : mpp){
            cout<<it.first<<"-> "<<it.second<<endl;
        }
        cout<<endl;
        
        int cntSwaps=0;
        for(int i=0; i<n; i=i+2){
            int first=row[i];
            // int second = first + ((first & 1) ? -1 : 1);
            int second = first^1;
            if(row[i+1] != second){
                cntSwaps++;
                int temp = mpp[second];
                mpp[row[i+1]] = temp;
                mpp[second]=i+1;
                swap(row[temp], row[i+1]);
            }
        }

        return cntSwaps;

    }
};