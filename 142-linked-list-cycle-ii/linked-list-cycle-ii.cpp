/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        if(head==NULL) return head;
        while(temp->next!=NULL && temp->val != 1e9){
            temp->val=1e9;
            temp=temp->next;
        }
        head = (temp->next == NULL)? NULL : temp;
        return head; 
    }
};