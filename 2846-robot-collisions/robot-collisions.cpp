class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
            vector<int> ans;
            int n = positions.size();
            map<pair<int, int>, pair<int, int>> mp;

            for(int i=0; i<n; i++){
                int position = positions[i];
                int health = healths[i];
                int flag = (directions[i] == 'R') ? 0 : 1 ;
                
                mp[{position, i}] = {health, flag};
            }   

            int direction = 0;
            stack <pair <pair<int, int>, pair<int, int> > > st;

            for(auto it : mp){

                int position = it.first.first;
                int idx = it.first.second;

                int health = it.second.first;
                int flag = it.second.second;

                // cout<<position<<" "<<idx<<" "<<health<<" "<<flag<<endl;

                if(flag == 0){
                    st.push({{position, idx}, {health, flag}});
                    continue;
                }

                while(!st.empty() && health > 0 && st.top().second.second == 0){
                    if(health == st.top().second.first){
                        health = 0;
                        st.pop();
                    }
                    else if(health > st.top().second.first){
                        health -= 1;
                        st.pop();
                    }
                    else{
                        health = 0;
                        st.top().second.first -= 1;
                    }
                }

                if(health > 0){
                    direction = flag;
                    st.push({{position, idx},{health, flag}});
                } 
            }

           map<int, int> mp2;  

            while(!st.empty()){
                int idx = st.top().first.second;
                int health = st.top().second.first;
                cout<<idx<<" "<<health<<endl;

                mp2[idx] = health;
                st.pop();
            }

            for(auto &it : mp2){
                ans.push_back(it.second);
            }

        return ans;
    }
};