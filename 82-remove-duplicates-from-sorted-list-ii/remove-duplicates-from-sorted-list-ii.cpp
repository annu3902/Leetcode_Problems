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
        if(head==NULL||head->next==NULL) return head; // Base Case

        ListNode* prev = new ListNode(INT_MAX);
        prev->next=head;

        // ListNode* prev=dummy;
        ListNode* curr=head;
        ListNode* front=head->next;
        prev->next=curr;

        ListNode* newHead=NULL;
        bool flag=false;

        while(front!=NULL && curr!=NULL){
            if(curr->val != front->val){
                if(flag==false){
                    flag=true;
                    newHead=curr;
                }
                prev=prev->next;
                curr=curr->next;
                front=front->next;
            }
            else{
                ListNode* temp=front;
                while(temp!=NULL && curr->val == temp->val){
                    temp=temp->next;
                }
                prev->next=temp;
                curr=temp;
                if(temp!=NULL){
                    front=temp->next;
                }
                if(front==NULL && flag==false){
                    newHead=curr;
                }
                // else front=NULL;
            }
        }
        return newHead;
    }
};