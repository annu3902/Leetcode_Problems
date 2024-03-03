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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode *temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        int m=size-n;
        if(m==0){
            head=head->next;
            return head;
        } 
        temp=head;
        while(m>1){
            temp=temp->next;
            m--;
        }
        
        ListNode* temp2 = temp->next;
        if(temp2->next){
            temp->next=temp2->next;
            temp2->next=NULL;
        }
        else if(temp2->next==NULL){
            temp->next=NULL;
        }
        // else{
        //     temp->next=NULL;
        // }
        return head;
    }
};