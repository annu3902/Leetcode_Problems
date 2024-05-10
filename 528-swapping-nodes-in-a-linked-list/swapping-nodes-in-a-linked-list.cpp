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
        int length=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            length++;
        }
        return length;
    }

    ListNode* swapNodes(ListNode* head, int k) {


        int cnt=1;
        ListNode* beg=head;
        while(cnt<k){
            beg=beg->next;
            cnt++;
        }

        int length=getLength(head);
        if(length==1) return head;
        int rem=length-k+1;
        int count=1;
        ListNode* end=head;
        while(count<rem){
            end=end->next;
            count++;
        }
        swap(end->val, beg->val);
        return head;
    }
};