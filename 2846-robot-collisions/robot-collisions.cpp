class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<int> index(n);
        iota(begin(index), end(index), 0);

        auto lambda = [&](int &i, int &j){
            return positions[i] < positions[j];
        };

        sort(begin(index), end(index), lambda);

        stack<int> st;
        vector<int> result;

        int i=0;
        while(i < n){
            int currIdx = index[i];
            if(directions[currIdx] == 'R'){
                st.push(index[i]);
                i++;
                continue;
            }

            while(!st.empty() && directions[st.top()] == 'R' && healths[currIdx] > 0){
                if(healths[currIdx] > healths[st.top()]){
                    healths[st.top()] = 0;
                    healths[currIdx] -= 1;
                    st.pop();
                }

                else if(healths[currIdx] < healths[st.top()]){
                    healths[currIdx] = 0;
                    healths[st.top()]-=1;
                    break;
                }

                else{
                    healths[currIdx] = 0;
                    healths[st.top()] = 0;
                    st.pop();
                    break;
                }
            }

            if(healths[currIdx] > 0){
                st.push(currIdx);
            }
            i++;

        }

        for(auto & health : healths){
            if(health > 0) result.push_back(health);
        }

        return result;

    }
};