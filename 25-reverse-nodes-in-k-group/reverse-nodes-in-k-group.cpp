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

    int getLength(ListNode* &head){
        int cnt=0;
        ListNode* temp=head;

        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=getLength(head);
        int patch=length/k;

        return solve(head, k, patch);
    }

    ListNode* solve(ListNode* &head, int k, int patch){
        if(patch==0) return head;

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* front=head->next;

        int cnt=0;
        while(curr!=NULL&&cnt<k){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            cnt++;
        }

        if(front!=NULL) {
            head->next=solve(curr, k, patch-1);
        }
        return prev;
    }
};