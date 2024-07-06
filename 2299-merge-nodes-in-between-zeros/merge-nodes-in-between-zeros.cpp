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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* newHead = NULL;
        ListNode* crawler = newHead;

        int sum = 0;
        while(temp){
            if(temp->val != 0){
                sum += temp->val;
            } 
            else{
                if(newHead == nullptr){
                    newHead = new ListNode(sum);
                    crawler = newHead;
                }

                else{
                    ListNode *newNode = new ListNode(sum);
                    crawler -> next = newNode;
                    crawler = crawler -> next;
                }
                sum = 0;
            }
            temp = temp->next;
        }

        return newHead;

    }
};