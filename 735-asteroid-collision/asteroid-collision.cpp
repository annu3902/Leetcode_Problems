class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        int i=0;
        int n = asteroids.size();

        while(i < n){

            if(st.empty() || (st.top() < 0 && asteroids[i] < 0) || (st.top() > 0 && asteroids[i] > 0)){
                st.push(asteroids[i]);
                i++;
                continue;
            }

            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                if(abs(st.top()) > abs(asteroids[i])){
                    asteroids[i] = 0;
                    break;
                }

                else if(abs(asteroids[i]) > abs(st.top())){
                    st.pop();
                }

                else{
                    asteroids[i] = 0;
                    st.pop();
                    break;
                }
            }

            if(asteroids[i] != 0){
                st.push(asteroids[i]);
            }

            i++;
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};





