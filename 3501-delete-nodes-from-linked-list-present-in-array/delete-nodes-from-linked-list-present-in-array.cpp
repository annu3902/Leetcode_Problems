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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* front = head;
        ListNode* prev = NULL;
        unordered_set<int> st (begin(nums), end(nums));

        while(front){

            if(st.find(front->val) != st.end()){
                if(front == head){
                    head = head->next;
                    front = front->next;
                }
                else{
                    prev->next = front->next;
                    front->next = NULL;
                    front = prev->next;
                }
            }
            else{
                prev = front;
                front = front->next;
            }

        }

        return head;
    }
};