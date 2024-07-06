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
        ListNode* newHead = head;
        ListNode* temp = newHead;
        ListNode* crawler = head->next;

        while(crawler){
            int sum = 0;

            while(crawler && crawler->val != 0){
                sum += crawler->val;
                crawler = crawler -> next;
            }
            temp->next->val = sum;
            temp = temp->next;

            crawler = crawler -> next;
        }

        temp->next = NULL;
        return newHead->next;
    }
};