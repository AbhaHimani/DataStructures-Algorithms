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
    // 1 2 3 4
    // 2 1 4 3
    // utna samajh nai aaya, but just did it anyway
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;
        ListNode curr = head;

        while (curr != null && curr.next != null) {
            prev.next = curr.next; //-1 2
            ListNode next = curr.next.next; //3
            curr.next.next = curr; //
            prev = curr;
            curr = next;
        }

        prev.next = curr;
        return dummy.next;
    }
}