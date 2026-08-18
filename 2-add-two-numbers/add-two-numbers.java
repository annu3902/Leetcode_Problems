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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode temp1 = l1;
        ListNode temp2 = l2;

        ListNode head = null;
        ListNode curr = null;

        int carry = 0;
        while(temp1 != null && temp2 != null){
            int sum = temp1.val + temp2.val;
            sum = ( sum + carry );
            carry = (sum >= 10) ? 1 : 0;

            sum = sum % 10;
            if(head == null){
                head = new ListNode(sum);
                curr = head;
            }
            else{
                curr.next = new ListNode(sum);
                curr = curr.next;
            }
            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        while(temp1 != null){
            int sum = (temp1.val + carry);
            carry = (sum >= 10) ? 1 : 0;

            sum = sum % 10;
            curr.next = new ListNode(sum);
            curr = curr.next;   
            temp1 = temp1.next;
        }

        while(temp2 != null){
            int sum = (temp2.val + carry);
            carry = (sum >= 10) ? 1 : 0;

            sum = sum % 10;
            curr.next = new ListNode(sum);
            curr = curr.next;
            temp2 = temp2.next;
        }

        if(carry == 1){
            curr.next = new ListNode(1);
            curr = curr.next;
        }

        return head;
    }
}