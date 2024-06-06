class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        int n = hand.size();
        map<int,int> mp;

        for(int &number : hand){
            mp[number]++;
        }

        while(!mp.empty()){
            auto it = mp.begin();
            int mini = it->first;
            mp[mini]--;
            if(mp[mini] == 0) mp.erase(mini);

            for(int i=1; i<groupSize; i++){
                if(mp.count(mini + i)){
                    cout<<mini+i<<" ";
                    mp[mini + i]--;
                    if(mp[mini + i] == 0){
                        mp.erase(mini + i);
                    }

                }
                else{
                    return false;
                }

            }
        }

        return true;

    }
};