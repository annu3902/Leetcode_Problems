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
    private ListNode reverse(ListNode prev, ListNode curr, ListNode next){

        if(next == null){
            curr.next = prev;
            return curr;
        }

        ListNode revHead = reverse(curr, next, next.next);
        
        curr.next = prev;

        return revHead;
    }

    public boolean isPalindrome(ListNode head) {
        // Find the middle of LL
        if(head == null || head.next == null) return true;

        ListNode fast = head;
        ListNode slow = head;

        while(slow != null && fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            // fast = (fast.next != null) ? fast.next.next : fast.next;
        }

        ListNode prev = null;
        ListNode curr = slow;
        ListNode next = curr.next;

        // // Reverse Linked List from the middle 
        // while(curr != null){
        //     curr.next = prev;
        //     prev= curr;
        //     curr = next;
        //     if(next != null){
        //         next = next.next;
        //     }
        // }

        ListNode revHead = reverse(prev, curr, next);

        ListNode temp1 = head;
        ListNode temp2 = revHead;

        while(temp1 != null && temp2 != null){
            if(temp1.val != temp2.val) return false;
            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        prev = null;
        curr = revHead;
        next = curr.next;

        ListNode revRevHead = reverse(prev, curr, next);

        return true;
    }
}