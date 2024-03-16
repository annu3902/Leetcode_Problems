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
        // Jab tak k carry h tab tak addition chlega
        // Agar node khtam ho jaye t nyi node lekr ans store krte h
        int carry=0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *head = NULL;
        ListNode *prev = head;
        ListNode *curr;

        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            int value = sum % 10;
            
            carry=(sum>=10)?1:0;
            ListNode* node = new ListNode(value);
            curr = node;
            if(prev==NULL){
                head = node;
                prev = head;
            }
            else{
                prev->next = curr;
                prev=curr;
                cout<<prev->val<<" ";
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1){
            int sum = temp1->val + carry;
            int value = sum % 10;
            ListNode *node = new ListNode(value);
            curr = node;
            prev->next=curr;
            prev=curr;
            carry = (sum>=10)?1:0;
            temp1=temp1->next;
        }

        while(temp2){
            int sum = temp2->val + carry;
            int value = sum % 10;
            ListNode *node = new ListNode(value);
            curr = node;
            prev->next=curr;
            prev=curr;
            carry = (sum>=10)?1:0;
            temp2=temp2->next;
        }
        if(carry){
            ListNode* node = new ListNode(1);
            curr = node;
            prev -> next = curr;
            prev=curr;
        }
        return head;
    }
};