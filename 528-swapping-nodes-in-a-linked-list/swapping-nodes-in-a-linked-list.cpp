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
    ListNode* swapNodes(ListNode* head, int k) {
        // If head is nullptr or k is invalid, return head as is
        // if (!head || k <= 0) {
        //     return head;
        // }

        int length = getLength(head);
        // If k is greater than the length of the list, return head as is
        if (k > length) {
            return head;
        }

        // Get k-th node from the start
        ListNode* prevBeg = nullptr;
        ListNode* beg = head;
        int cnt = 1;
        while (cnt < k) {
            prevBeg = beg;
            beg = beg->next;
            cnt++;
        }

        // Get k-th node from the end
        int rem = length - k + 1;
        ListNode* prevEnd = nullptr;
        ListNode* end = head;
        ListNode* forEnd = head->next;
        int count = 1;
        while (count < rem) {
            prevEnd = end;
            end = end->next;
            forEnd = forEnd->next;
            count++;
        }

        // Now swap the nodes
        // Handle case when one of them is the head
        if (prevBeg) {
            prevBeg->next = end;
        } else {
            head = end; // If beg is head, adjust head pointer
        }

        if (prevEnd) {
            prevEnd->next = beg;
        } else {
            head = beg; // If end is head, adjust head pointer
        }

        // Swap the next pointers of the nodes
        ListNode* temp = beg->next;
        beg->next = end->next;
        end->next = temp;

        return head;
    }

    int getLength(ListNode* &head){
        ListNode* temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        return length;
    }
};