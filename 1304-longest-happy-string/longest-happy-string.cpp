class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});

        string ans;
        while(pq.top().first){
            auto [x,c] = pq.top(); pq.pop();
            
            if(ans.size() < 2 || ans.back() != c || ans[ans.size()-2] != c){
                ans += c;
                x -= 1;
            }
            else{
                auto [y,d] = pq.top(); pq.pop();
                if(!y) break;
                ans += d;
                y -= 1;
                pq.push({y,d});
            }
            pq.push({x,c});
        }
        return ans;
    }
};