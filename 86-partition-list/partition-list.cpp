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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        
        ListNode* smallDummy = new ListNode(-1);
        ListNode* smallHead = smallDummy;
        ListNode* largeDummy = new ListNode(-2);
        ListNode* largeHead = largeDummy;

        ListNode* temp = head;

        while(temp){

            if(temp->val<x){
                smallDummy->next = temp;
                smallDummy = smallDummy->next;
            }

            else{
                largeDummy->next = temp;
                largeDummy = largeDummy->next;
            }
            temp = temp->next;
        }
            smallDummy->next = NULL;
            largeDummy->next = NULL;

        smallDummy->next = largeHead->next;
        return smallHead->next;
    }
};