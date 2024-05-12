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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr||head->next==nullptr) return head;

        int len=getLength(head);
        k%=len;
        if(k==0) return head;

        ListNode* temp=head;
        ListNode* newHead=NULL;

        int cnt=1;

        while(temp->next&&cnt<len-k){
            temp=temp->next;
            cnt++;
        }

        // cout<<temp->val<<" ";
        newHead=temp->next;
        temp->next=NULL;
        // cout<<newHead->val<<" ";

        temp=newHead;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }


    int getLength(ListNode* &head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};