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

    ListNode* insertAtHead(ListNode* &curr, int value){
        ListNode* temp = new ListNode(value);
        temp->next = curr;
        curr=temp;
        return curr;
    }

    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        // Inserting nodes to stack;
        ListNode* temp = head;
        while(temp->next){
            st.push(temp->val);
            temp=temp->next;
        }

        ListNode* curr = new ListNode(temp->val); 
        int maxi = curr->val;
        while(!st.empty()){
            if(maxi <= st.top()){
                maxi = st.top();
                insertAtHead(curr, maxi);
            }
            st.pop();
        }
        return curr;
    }
};