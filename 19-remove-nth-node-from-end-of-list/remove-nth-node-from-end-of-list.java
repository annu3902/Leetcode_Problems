/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int size = 0;
        ListNode temp = head;

        while(temp != null){
            temp = temp.next;
            size++;
        }

        int front = size - n + 1;

        ListNode curr = head;
        ListNode prev = null;
        for(int i=1; i<front; i++){
            prev = curr;
            curr = curr.next;
        }

        if(head == curr){
            head = head.next;
        }
        if(prev != null) prev.next = curr.next;
        curr.next = null;
        
        return head;
    }
}