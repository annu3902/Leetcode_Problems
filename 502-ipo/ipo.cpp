class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int, int>> p;

        for(int i=0; i < n; i++){
            p.push_back({capital[i], profits[i]});
        }

        sort(begin(p), end(p));

        priority_queue<int> pq;

        int i = 0;
        while(k > 0){

            for(; i<n; i++){
                if(p[i].first <= w){
                    pq.push(p[i].second);
                }
                else{
                    break;
                }
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
            k--;
        }

        return w;
    
    }
};