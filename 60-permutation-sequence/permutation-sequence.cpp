class Solution {
public:
void permutation_generator(int ind, int curr_val, int n, vector<bool> &taken, vector<int> &sequences){

    if(ind >= n){
        sequences.push_back(curr_val);
        return;
    }
        
        for(int i=1; i<=n; i++){
            if(!taken[i]){
                taken[i] = 1;
                curr_val = curr_val*10 + i;
                permutation_generator(ind + 1, curr_val, n, taken, sequences);
                // Now Backtracking
                curr_val /= 10;
                taken[i] = 0;
            }

        }
    }

    string getPermutation(int n, int k) {
        vector<bool> taken(n+1, 0);
        vector<int> sequences;
        permutation_generator(0, 0, n, taken,sequences);
        return to_string(sequences[k-1]);

    }
};