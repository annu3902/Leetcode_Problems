class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;
        int count = 0;
        int n = sandwiches.size();
        for(int i=n-1; i>=0; i--){
            st.push(sandwiches[i]);
        }

        int m=students.size();
        for(int i=0; i<=m-1; i++){
            q.push(students[i]);
        }

        while(!st.empty()){
            int top = st.top();
            int front = q.front();

            if(top == front){
                st.pop();
                q.pop();
                count = 0;
                continue;
            }
            else{
                count++;
                q.pop();
                q.push(front);
                if(count==q.size()) return q.size();
                
            }
        }
        return 0;
    }

};