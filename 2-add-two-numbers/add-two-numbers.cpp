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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            carry = sum/10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            if(head == NULL){
                head = temp;
                curr = temp;
            }else{
                curr->next = temp;
                curr = temp;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1){
            int sum = temp1->val + carry;
            carry = sum/10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            curr = temp;
            temp1 = temp1->next;
        }

        while(temp2){
            int sum = temp2->val + carry;
            carry = sum/10;
            sum %= 10;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            curr = temp;
            temp2 = temp2->next;
        }

        if(carry == 1){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }

        return head;

    }
};