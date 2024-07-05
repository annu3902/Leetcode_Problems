/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next ==NULL) return {-1, -1};

        // priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> pq;


        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* front = head->next; 
        int count = 0;

        while(curr){
            if(prev && front){
                if((front->val > curr->val && prev->val > curr->val) || (front->val < curr->val && curr->val > prev->val)){
                    pq.push_back(count);
                }
            }
            prev = curr;
            curr = curr->next;
            if(front) front = front->next;
            count++;

        }

        sort(begin(pq), end(pq));
        int mini = INT_MAX;

        if(pq.size() >= 2){
            for(int i=1; i < pq.size(); i++){
                mini = min(mini, pq[i] - pq[i-1]);
            }

            return {mini, pq[pq.size()-1] - pq[0]};
        }

        return {-1,-1};

    }
};