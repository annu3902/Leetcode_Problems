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
    int size(ListNode* &head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* solve(ListNode* &head, ListNode* prev, ListNode* curr){
        if(head==NULL) return head;
        head=curr;
        curr=curr->next;
        head->next=prev;
        prev->next=NULL;
        prev=head;
        head=head->next;
        return solve(head, prev, curr);
    }

    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL || size(head) == 1) return head;
    //     ListNode* prev=head;
    //     ListNode* curr=prev->next;
    //     return solve(head, prev, curr);
    // }

    ListNode* reverseList(ListNode* head){
        if(head == NULL || size(head) == 1) return head;
        ListNode* temp = head;
        ListNode* prev = temp;
        ListNode* curr = prev->next;
        temp = temp->next;
        bool flag=0;

        while(temp){
            curr=curr->next;
            temp->next=prev;
            if(flag==0){
                prev->next=NULL;
                flag=1;
            }
            prev=temp;
            temp=curr;
        }
        head=prev;
        return head;
    }
};