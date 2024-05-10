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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL) return head;
        int length = getLength(head);

        int mid = length/2;

        ListNode* temp = head;
        while(mid){
            temp = temp->next;
            mid--;
        }
        return temp;
    }

    int getLength(ListNode* head){
        int length = 0;

        while(head){
            length++;
            head = head->next;
        }
        return length;
    }
};