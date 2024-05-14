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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; // Base Case
        // Fiding mid
        ListNode* mid = middleOfLL(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // sORT BOTH THE LIST   
        left = sortList(left);
        right = sortList(right);

        // MERGE THE LIST
        ListNode* result = merge2LL(left, right);
        return result;
    }

    ListNode* middleOfLL(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge2LL(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                dummy->next = left;
                left = left->next;
            }
            else{
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }

        if(!left && right){
            dummy->next = right;
        }
        else if(!right && left){
            dummy->next = left;
        }
        
        return ans->next;
    }
};