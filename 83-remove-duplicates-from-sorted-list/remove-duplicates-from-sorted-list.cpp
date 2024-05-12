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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=head;
        ListNode* next=head->next;

        while(next){
            if(prev->val == next->val){
                prev->next=next->next;
                next->next=NULL;
                delete(next);
                next=prev->next;
            }
            else{
                prev=prev->next;
                next=next->next;
            }
        }
        return head;
    }
};