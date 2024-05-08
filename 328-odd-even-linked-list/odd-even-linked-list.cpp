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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == nullptr || head->next->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* start = even;

        ListNode* temp = head->next->next;
        int cnt=3;

        while(temp){
            if(cnt & 1){
                // odd hai
                odd->next = temp;
                odd=temp;
            }
            else{
                // even hai
                even->next = temp;
                even=temp;
            }
            cnt++;
            temp = temp->next;
        }

        odd->next=start;
        even->next=NULL;
        return head;

    }
};