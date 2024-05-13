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
    ListNode* getPointer(ListNode* &head, int k){
        ListNode* temp=head;
        int cnt=1;

        while(cnt<k){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }

    // ListNode* reverse(ListNode* head){

    // }

    int getLength(ListNode* &head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base Case
        if(head->next==NULL || left==right) return head;
        int length = getLength(head);
        // if(length == right && left == 1) reverse

        ListNode* leftPtr = getPointer(head, left);
        ListNode* rightPtr = getPointer(head, right);

        // step 1. reverse from left to right
        ListNode* curr=leftPtr;
        ListNode* prev=NULL;
        ListNode* front=leftPtr->next;
        // ListNode* temp=left;

        while(front!=NULL && curr!=rightPtr){
            curr->next=prev;
            prev=curr;
            curr=front;
            front=front->next;
        }
        curr->next=prev;
        curr=front;

        // step 2
        prev=head;
        if(prev!=leftPtr){
            ListNode* temp=head->next;
            while(temp!=NULL && temp!=leftPtr){
                prev=prev->next;
                temp=temp->next;
            }
            prev->next=rightPtr;
            leftPtr->next=curr;
        }
        else{
            head=rightPtr;
            leftPtr->next=curr;
            // return head;
        }

        return head;
    }


    
};