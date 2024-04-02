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
        if(head == NULL) return NULL;
        ListNode* temp = head;
        while(temp && temp->val != 1e9){
            temp->val=1e9;
            temp=temp->next;
        }
        head = (temp == NULL) ? NULL : temp;
        return head;
    }
};