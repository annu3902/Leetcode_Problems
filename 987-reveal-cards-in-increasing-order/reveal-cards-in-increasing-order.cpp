class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // return deck;
        int n=deck.size();
        sort(deck.begin(), deck.end());
        vector<int> ans(n,0);

        int i=0;
        int j=0; 
        bool skip = false;

        while(i<n){ 

            if(ans[j] == 0){
                if(skip == 0){ // khali hai
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip; // alternate positions
            }

            j = (j+1)%n;

        }
        return ans;
    }
};