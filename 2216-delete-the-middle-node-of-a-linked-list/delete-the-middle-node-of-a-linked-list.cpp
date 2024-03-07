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
    ListNode* deleteMiddle(ListNode* head) {
        int size=0;
        ListNode*temp=head;

        while(temp){
            size++;
            temp=temp->next;
        }

        int mid=(size/2)-1;
        temp=head;
        // if(mid<0) return head;
        while(mid>0){
            mid--;
            temp=temp->next;
        }
        if(temp->next==NULL) return head=temp->next;
        ListNode*temp2=temp->next;
        temp->next=temp2->next;
        return head;
    }
};