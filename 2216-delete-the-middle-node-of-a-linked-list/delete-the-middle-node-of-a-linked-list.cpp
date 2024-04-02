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
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int mid = floor(size(head)/2);
        // if(size(head) == 1) return head->next;
        int node=0;
        while(node<mid-1){
            temp=temp->next;
            node++;
        }
        if(temp->next == NULL) return head = temp->next;
        ListNode* temp2 = temp->next;
        temp->next=temp2->next;
        temp2->next=NULL;
        return head;
    }
};